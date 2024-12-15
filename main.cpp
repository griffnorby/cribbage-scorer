#include <iostream>
#include <sstream>
#include <vector>

#include "card.h"
#include "scorer.h"

int main()
{
    std::vector<cribbage::deck::card*> cards;
    std::vector<cribbage::deck::card*> cut_cards;

    std::string input;
    std::stringstream stream;

    std::cout << "Enter the hand to be scored: " << std::endl;

    std::getline(std::cin, input);

    stream.str(input);

    for(std::string value; std::getline(stream, value, ' ');)
    {
        cards.push_back(cribbage::deck::card::parse(value));
    }

    stream.clear();

    std::cout << "Enter the cut card(s): " << std::endl;

    std::getline(std::cin, input);

    stream.str(input);

    for(std::string value; std::getline(stream, value, ' ');)
    {
        cut_cards.push_back(cribbage::deck::card::parse(value));
    }

    stream.clear();

    cribbage::scoring::scorer scorer(cards, cut_cards);

    scorer.generate_combinations();
    scorer.score_fifteens();
    scorer.score_pairs();
    scorer.score_runs();
    scorer.score_knobs();
    scorer.score_flush();

    long points = scorer.points_from_fifteens
                + scorer.points_from_pairs
                + scorer.points_from_runs
                + scorer.points_from_knobs
                + scorer.points_from_flush;

    std::cout << "Fifteens: " << scorer.points_from_fifteens << std::endl;
    std::cout << "Pairs: " << scorer.points_from_pairs << std::endl;
    std::cout << "Runs: " << scorer.points_from_runs << std::endl;
    std::cout << "Knobs: " << scorer.points_from_knobs << std::endl;
    std::cout << "Flush: " << scorer.points_from_flush << std::endl;
    std::cout << "Points: " << points << std::endl;

    return 0;
}