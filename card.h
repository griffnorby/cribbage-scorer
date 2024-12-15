#ifndef CARD_H
#define CARD_H

#include "denomination.h"
#include "suit.h"

namespace cribbage
{
    namespace deck
    {
        struct card
        {
            const cribbage::deck::denomination* denomination;
            const cribbage::deck::suit* suit;
            int sorting_value;
            std::string identifier;
            std::string name;

            card(const deck::denomination& denomination, const deck::suit& suit);

            friend bool operator ==(const card& lhs, const card& rhs);

            friend bool operator !=(const card& lhs, const card& rhs);

            friend bool operator <(const card& lhs, const card& rhs);

            friend bool operator >(const card& lhs, const card& rhs);

            static card* parse(std::string& str);
        };

        static card ace_of_clubs(ace, clubs);
        static card two_of_clubs(two, clubs);
        static card three_of_clubs(three, clubs);
        static card four_of_clubs(four, clubs);
        static card five_of_clubs(five, clubs);
        static card six_of_clubs(six, clubs);
        static card seven_of_clubs(seven, clubs);
        static card eight_of_clubs(eight, clubs);
        static card nine_of_clubs(nine, clubs);
        static card ten_of_clubs(ten, clubs);
        static card jack_of_clubs(jack, clubs);
        static card queen_of_clubs(queen, clubs);
        static card king_of_clubs(king, clubs);
        static card ace_of_diamonds(ace, diamonds);
        static card two_of_diamonds(two, diamonds);
        static card three_of_diamonds(three, diamonds);
        static card four_of_diamonds(four, diamonds);
        static card five_of_diamonds(five, diamonds);
        static card six_of_diamonds(six, diamonds);
        static card seven_of_diamonds(seven, diamonds);
        static card eight_of_diamonds(eight, diamonds);
        static card nine_of_diamonds(nine, diamonds);
        static card ten_of_diamonds(ten, diamonds);
        static card jack_of_diamonds(jack, diamonds);
        static card queen_of_diamonds(queen, diamonds);
        static card king_of_diamonds(king, diamonds);
        static card ace_of_hearts(ace, hearts);
        static card two_of_hearts(two, hearts);
        static card three_of_hearts(three, hearts);
        static card four_of_hearts(four, hearts);
        static card five_of_hearts(five, hearts);
        static card six_of_hearts(six, hearts);
        static card seven_of_hearts(seven, hearts);
        static card eight_of_hearts(eight, hearts);
        static card nine_of_hearts(nine, hearts);
        static card ten_of_hearts(ten, hearts);
        static card jack_of_hearts(jack, hearts);
        static card queen_of_hearts(queen, hearts);
        static card king_of_hearts(king, hearts);
        static card ace_of_spades(ace, spades);
        static card two_of_spades(two, spades);
        static card three_of_spades(three, spades);
        static card four_of_spades(four, spades);
        static card five_of_spades(five, spades);
        static card six_of_spades(six, spades);
        static card seven_of_spades(seven, spades);
        static card eight_of_spades(eight, spades);
        static card nine_of_spades(nine, spades);
        static card ten_of_spades(ten, spades);
        static card jack_of_spades(jack, spades);
        static card queen_of_spades(queen, spades);
        static card king_of_spades(king, spades);
    }
}

#endif