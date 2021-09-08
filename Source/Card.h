#pragma once

#include "Literals.h"

namespace Poker
{
    struct Card
    {
        u8 suit;
        u8 value;

        static constexpr u8 NumSuits = 4;
        static constexpr u8 NumValues = 13;

        static constexpr const char* SuitStrings[NumSuits] =
        {
            "Heart",
            "Spade",
            "Club",
            "Diamond"
        };

        static constexpr const char* ValueStrings[NumValues] =
        {
            "Ace",
            "Two",
            "Three",
            "Four",
            "Five",
            "Six",
            "Seven",
            "Eight",
            "Nine",
            "Ten",
            "Jack",
            "Queen",
            "King"
        };
    };
}