#include <algorithm>
#include <stdexcept>

#include "denomination.h"

namespace cribbage
{
    namespace deck
    {
        denomination::denomination(const int sorting_value, const int sequential_value, const int arithmetic_value, const std::string& identifier, const std::string& name)
        {
            this->sorting_value = sorting_value;
            this->sequential_value = sequential_value;
            this->arithmetic_value = arithmetic_value;
            this->identifier = identifier;
            this->name = name;
        }

        bool operator ==(const denomination& lhs, const denomination& rhs)
        {
            return lhs.sorting_value == rhs.sorting_value;
        }

        bool operator !=(const denomination& lhs, const denomination& rhs)
        {
            return !(lhs == rhs);
        }

        bool operator <(const denomination& lhs, const denomination& rhs)
        {
            return lhs.sorting_value < rhs.sorting_value;
        }

        bool operator >(const denomination& lhs, const denomination& rhs)
        {
            return lhs.sorting_value > rhs.sorting_value;
        }

        bool denomination::precedes(const denomination& other) const
        {
            return other.sorting_value - sorting_value == 1;
        }

        bool denomination::follows(const denomination& other) const
        {
            return sorting_value - other.sorting_value == 1;
        }

        denomination* denomination::parse(std::string& str)
        {
            std::transform(str.begin(), str.end(), str.begin(), tolower);

            if(str == "a" || str == "ace") return &ace;
            if(str == "2" || str == "two") return &two;
            if(str == "3" || str == "three") return &three;
            if(str == "4" || str == "four") return &four;
            if(str == "5" || str == "five") return &five;
            if(str == "6" || str == "six") return &six;
            if(str == "7" || str == "seven") return &seven;
            if(str == "8" || str == "eight") return &eight;
            if(str == "9" || str == "nine") return &nine;
            if(str == "10" || str == "ten") return &ten;
            if(str == "j" || str == "jack") return &jack;
            if(str == "q" || str == "queen") return &queen;
            if(str == "k" || str == "king") return &king;

            throw std::invalid_argument("denomination::parse(): invalid denomination identifier or name");
        }
    }
}