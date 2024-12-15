#include <algorithm>
#include <future>
#include <numeric>

#include "scorer.h"

namespace cribbage
{
    namespace scoring
    {
        scorer::scorer(const std::vector<deck::card*>& cards, const std::vector<deck::card*>& cut_cards)
        {
            this->cards = cards;
            this->cut_cards = cut_cards;
            this->combined_cards = std::vector<deck::card*>(cards.size() + cut_cards.size());

            std::merge(cards.begin(), cards.end(), cut_cards.begin(), cut_cards.end(), combined_cards.begin());

            sort();
        }

        void scorer::sort()
        {
            auto comparator = [](const deck::card* a, const deck::card* b)
            {
                return a->denomination == b->denomination ? a->suit < b->suit : a->denomination < b->denomination;
            };

            std::sort(cards.begin(), cards.end(), comparator);
            std::sort(cut_cards.begin(), cut_cards.end(), comparator);
            std::sort(combined_cards.begin(), combined_cards.end(), comparator);
        }


        void scorer::generate_combinations()
        {
            auto task = std::async(std::launch::async, [&]
            {
                std::vector<std::vector<deck::card*>> combinations;

                for(auto mask = 0; mask < (1 << combined_cards.size()); mask++)
                {
                    std::vector<deck::card*> combination;

                    for(auto index = 0; index < combined_cards.size(); index++)
                    {
                        if((1 << index) & mask)
                        {
                            combination.push_back(combined_cards[index]);
                        }
                    }

                    combinations.push_back(combination);
                }

                return combinations;
            });

            task.wait();

            this->combinations = task.get();
            this->combinations_generated = true;
        }

        void scorer::score_fifteens()
        {
            auto task = std::async(std::launch::async, [&]
            {
                return std::count_if(combinations.begin(), combinations.end(), [&](const std::vector<deck::card*>& combination)
                {
                    return std::accumulate(combination.begin(), combination.end(), 0, [&](const int sum, const deck::card* card)
                    {
                        return sum + card->denomination->arithmetic_value;
                    }) == 15;
                }) * POINTS_FROM_FIFTEEN;
            });

            task.wait();

            this->points_from_fifteens = task.get();
            this->fifteens_scored = true;
        }

        void scorer::score_pairs()
        {
            auto task = std::async(std::launch::async, [&]
            {
                return std::count_if(combinations.begin(), combinations.end(), [&](const std::vector<deck::card*>& combination)
                {
                    return combination.size() == 2 && combination[0]->denomination == combination[1]->denomination;
                }) * POINTS_FROM_PAIR;
            });

            task.wait();

            this->points_from_pairs = task.get();
            this->pairs_scored = true;
        }

        void scorer::score_runs()
        {
            std::function<int(std::vector<deck::card*>&)> score_run = [&](const std::vector<deck::card*>& cards)
            {
                auto length = 1;
                auto multiplier = 1;

                std::vector<deck::card*> copy = cards;

                const deck::card* previous = nullptr;

                for(auto index = 0; index < cards.size() - 1; index++)
                {
                    const deck::card* current = cards[index];
                    const deck::card* next = cards[index + 1];

                    if(current->denomination == next->denomination)
                    {
                        if(previous == nullptr || current->denomination != previous->denomination)
                        {
                            multiplier *= 2;
                        }
                        else if(multiplier != 3)
                        {
                            multiplier += multiplier / 2;
                        }
                        else
                        {
                            multiplier++;
                        }

                        previous = current;
                    }
                    else if(current->denomination->precedes(*next->denomination))
                    {
                        length++;
                    }
                    else if(length < 3)
                    {
                        length = 1;
                        multiplier = 1;
                    }

                    if(!copy.empty())
                    {
                        copy.erase(copy.begin());
                    }

                    if(index == copy.size())
                    {
                        break;
                    }
                }

                if(length >= 3)
                {
                    return ((length * multiplier) * POINTS_FROM_RUN_MEMBER) + score_run(copy);
                }

                return 0;
            };

            auto task = std::async(std::launch::async, [&]
            {
                return score_run(combined_cards);
            });

            task.wait();

            this->points_from_runs = task.get();
            this->runs_scored = true;
        }

        void scorer::score_knobs()
        {
            auto task = std::async(std::launch::async, [&]
            {
                return std::accumulate(cards.begin(), cards.end(), 0L, [&](auto sum, const deck::card* card)
                {
                    if(card->denomination != &deck::jack)
                    {
                        return sum;
                    }

                    return sum + std::count_if(cut_cards.begin(), cut_cards.end(), [&](const deck::card* cut_card)
                    {
                        return card->suit == cut_card->suit;
                    });
                }) * POINTS_FROM_KNOBS;
            });

            task.wait();

            this->points_from_knobs = task.get();
            this->knobs_scored = true;
        }

        void scorer::score_flush()
        {
            auto task = std::async(std::launch::async, [&]
            {
                return (std::all_of(cards.begin() + 1, cards.end(), [&](const deck::card* card)
                {
                    return card->suit == cards[0]->suit;
                }) ? cards.size() + std::count_if(cut_cards.begin(), cut_cards.end(), [&](const deck::card* cut_card)
                                    {
                                        return cut_card->suit == cards[0]->suit;
                                    }) : 0) * POINTS_FROM_FLUSH_MEMBER;
            });

            task.wait();

            this->points_from_flush = task.get();
            this->flush_scored = true;
        }
    }
}
