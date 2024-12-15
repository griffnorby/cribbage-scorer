#ifndef SCORER_H
#define SCORER_H

#include <vector>

#include "card.h"

#define POINTS_FROM_FIFTEEN 2
#define POINTS_FROM_PAIR 2
#define POINTS_FROM_RUN_MEMBER 1
#define POINTS_FROM_KNOBS 1
#define POINTS_FROM_FLUSH_MEMBER 1

namespace cribbage
{
    namespace scoring
    {
        struct scorer
        {
            std::vector<deck::card*> cards;
            std::vector<deck::card*> cut_cards;
            std::vector<deck::card*> combined_cards;

            std::vector<std::vector<deck::card*>> combinations;
            bool combinations_generated = false;

            long points_from_fifteens = 0;
            bool fifteens_scored = false;

            long points_from_pairs = 0;
            bool pairs_scored = false;

            long points_from_runs = 0;
            bool runs_scored = false;

            long points_from_knobs = 0;
            bool knobs_scored = false;

            long points_from_flush = 0;
            bool flush_scored = false;

            scorer(const std::vector<deck::card*>& cards, const std::vector<deck::card*>& cut_cards);

            void sort();

            void generate_combinations();

            void score_fifteens();

            void score_pairs();

            void score_runs();

            void score_knobs();

            void score_flush();
        };
    }
}

#endif