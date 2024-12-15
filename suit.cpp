#include <algorithm>
#include <stdexcept>

#include "suit.h"

namespace cribbage
{
    namespace deck
    {
        suit::suit(const int sorting_value, const std::string& identifier, const std::string& name)
        {
            this->sorting_value = sorting_value;
            this->identifier = identifier;
            this->name = name;
        }

        bool operator ==(const suit& lhs, const suit& rhs)
        {
            return lhs.sorting_value == rhs.sorting_value;
        }

        bool operator !=(const suit& lhs, const suit& rhs)
        {
            return !(lhs == rhs);
        }

        bool operator <(const suit& lhs, const suit& rhs)
        {
            return lhs.sorting_value < rhs.sorting_value;
        }

        bool operator >(const suit& lhs, const suit& rhs)
        {
            return lhs.sorting_value > rhs.sorting_value;
        }

        suit* suit::parse(std::string& str)
        {
            std::transform(str.begin(), str.end(), str.begin(), tolower);

            if(str == "c" || str == "clubs") return &clubs;
            if(str == "d" || str == "diamonds") return &diamonds;
            if(str == "h" || str == "hearts") return &hearts;
            if(str == "s" || str == "spades") return &spades;

            throw std::invalid_argument("suit::parse(): invalid suit identifier or name");
        }
    }
}