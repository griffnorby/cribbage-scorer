#ifndef SUIT_H
#define SUIT_H

#include <string>

namespace cribbage
{
    namespace deck
    {
        struct suit
        {
            int sorting_value;
            std::string identifier;
            std::string name;

            suit(int sorting_value, const std::string& identifier, const std::string& name);

            friend bool operator ==(const suit& lhs, const suit& rhs);

            friend bool operator !=(const suit& lhs, const suit& rhs);

            friend bool operator <(const suit& lhs, const suit& rhs);

            friend bool operator >(const suit& lhs, const suit& rhs);

            static suit* parse(std::string& str);
        };

        static suit clubs(0, "c", "clubs");
        static suit diamonds(1, "d", "diamonds");
        static suit hearts(2, "h", "hearts");
        static suit spades(3, "s", "spades");
    }
}

#endif