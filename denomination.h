#ifndef DENOMINATION_H
#define DENOMINATION_H

#include <string>

namespace cribbage
{
    namespace deck
    {
        struct denomination
        {
            int sorting_value;
            int sequential_value;
            int arithmetic_value;
            std::string identifier;
            std::string name;

            denomination(int sorting_value, int sequential_value, int arithmetic_value, const std::string& identifier, const std::string& name);

            friend bool operator ==(const denomination& lhs, const denomination& rhs);

            friend bool operator !=(const denomination& lhs, const denomination& rhs);

            friend bool operator <(const denomination& lhs, const denomination& rhs);

            friend bool operator >(const denomination& lhs, const denomination& rhs);

            bool precedes(const denomination& other) const;

            bool follows(const denomination& other) const;

            static denomination* parse(std::string& str);
        };

        static denomination ace(0, 1, 1, "a", "ace");
        static denomination two(1, 2, 2, "2", "two");
        static denomination three(2, 3, 3, "3", "three");
        static denomination four(3, 4, 4, "4", "four");
        static denomination five(4, 5, 5, "5", "five");
        static denomination six(5, 6, 6, "6", "six");
        static denomination seven(6, 7, 7, "7", "seven");
        static denomination eight(7, 8, 8, "8", "eight");
        static denomination nine(8, 9, 9, "9", "nine");
        static denomination ten(9, 10, 10, "10", "ten");
        static denomination jack(10, 11, 10, "j", "jack");
        static denomination queen(11, 12, 10, "q", "queen");
        static denomination king(12, 13, 10, "k", "king");
    }
}

#endif