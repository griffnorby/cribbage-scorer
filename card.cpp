#include <algorithm>
#include <stdexcept>

#include "card.h"

namespace cribbage
{
    namespace deck
    {
        card::card(const deck::denomination& denomination, const deck::suit& suit)
        {
            this->denomination = &denomination;
            this->suit = &suit;
            this->sorting_value = (suit.sorting_value * 13) + denomination.sorting_value;
            this->identifier = denomination.identifier + suit.identifier;
            this->name = denomination.name + " of " + suit.name;
        }

        bool operator ==(const card& lhs, const card& rhs)
        {
            return lhs.sorting_value == rhs.sorting_value;
        }

        bool operator !=(const card& lhs, const card& rhs)
        {
            return !(lhs == rhs);
        }

        bool operator <(const card& lhs, const card& rhs)
        {
            return lhs.sorting_value < rhs.sorting_value;
        }

        bool operator >(const card& lhs, const card& rhs)
        {
            return lhs.sorting_value > rhs.sorting_value;
        }

        card* card::parse(std::string& str)
        {
            std::transform(str.begin(), str.end(), str.begin(), tolower);

            if(str == "ac" || str == "ace of clubs") return &ace_of_clubs;
            if(str == "2c" || str == "two of clubs") return &two_of_clubs;
            if(str == "3c" || str == "three of clubs") return &three_of_clubs;
            if(str == "4c" || str == "four of clubs") return &four_of_clubs;
            if(str == "5c" || str == "five of clubs") return &five_of_clubs;
            if(str == "6c" || str == "six of clubs") return &six_of_clubs;
            if(str == "7c" || str == "seven of clubs") return &seven_of_clubs;
            if(str == "8c" || str == "eight of clubs") return &eight_of_clubs;
            if(str == "9c" || str == "nine of clubs") return &nine_of_clubs;
            if(str == "10c" || str == "ten of clubs") return &ten_of_clubs;
            if(str == "jc" || str == "jack of clubs") return &jack_of_clubs;
            if(str == "qc" || str == "queen of clubs") return &queen_of_clubs;
            if(str == "kc" || str == "king of clubs") return &king_of_clubs;
            if(str == "ad" || str == "ace of diamonds") return &ace_of_diamonds;
            if(str == "2d" || str == "two of diamonds") return &two_of_diamonds;
            if(str == "3d" || str == "three of diamonds") return &three_of_diamonds;
            if(str == "4d" || str == "four of diamonds") return &four_of_diamonds;
            if(str == "5d" || str == "five of diamonds") return &five_of_diamonds;
            if(str == "6d" || str == "six of diamonds") return &six_of_diamonds;
            if(str == "7d" || str == "seven of diamonds") return &seven_of_diamonds;
            if(str == "8d" || str == "eight of diamonds") return &eight_of_diamonds;
            if(str == "9d" || str == "nine of diamonds") return &nine_of_diamonds;
            if(str == "10d" || str == "ten of diamonds") return &ten_of_diamonds;
            if(str == "jd" || str == "jack of diamonds") return &jack_of_diamonds;
            if(str == "qd" || str == "queen of diamonds") return &queen_of_diamonds;
            if(str == "kd" || str == "king of diamonds") return &king_of_diamonds;
            if(str == "ah" || str == "ace of hearts") return &ace_of_hearts;
            if(str == "2h" || str == "two of hearts") return &two_of_hearts;
            if(str == "3h" || str == "three of hearts") return &three_of_hearts;
            if(str == "4h" || str == "four of hearts") return &four_of_hearts;
            if(str == "5h" || str == "five of hearts") return &five_of_hearts;
            if(str == "6h" || str == "six of hearts") return &six_of_hearts;
            if(str == "7h" || str == "seven of hearts") return &seven_of_hearts;
            if(str == "8h" || str == "eight of hearts") return &eight_of_hearts;
            if(str == "9h" || str == "nine of hearts") return &nine_of_hearts;
            if(str == "10h" || str == "ten of hearts") return &ten_of_hearts;
            if(str == "jh" || str == "jack of hearts") return &jack_of_hearts;
            if(str == "qh" || str == "queen of hearts") return &queen_of_hearts;
            if(str == "kh" || str == "king of hearts") return &king_of_hearts;
            if(str == "as" || str == "ace of spades") return &ace_of_spades;
            if(str == "2s" || str == "two of spades") return &two_of_spades;
            if(str == "3s" || str == "three of spades") return &three_of_spades;
            if(str == "4s" || str == "four of spades") return &four_of_spades;
            if(str == "5s" || str == "five of spades") return &five_of_spades;
            if(str == "6s" || str == "six of spades") return &six_of_spades;
            if(str == "7s" || str == "seven of spades") return &seven_of_spades;
            if(str == "8s" || str == "eight of spades") return &eight_of_spades;
            if(str == "9s" || str == "nine of spades") return &nine_of_spades;
            if(str == "10s" || str == "ten of spades") return &ten_of_spades;
            if(str == "js" || str == "jack of spades") return &jack_of_spades;
            if(str == "qs" || str == "queen of spades") return &queen_of_spades;
            if(str == "ks" || str == "king of spades") return &king_of_spades;

            throw std::invalid_argument("card::parse(): invalid card identifier or name");
        }
    }
}