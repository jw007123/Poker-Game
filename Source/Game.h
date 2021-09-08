#pragma once

#include "Literals.h"
#include "Card.h"
#include "Scoring.h"

#include <random>
#include <iostream>

namespace Poker
{
    class Game
    {
    public:
        Game();
        ~Game();

        /// If true, user has won and their winnings should be doubled
        bool DoubleOrNothing();

        /// Performs a standard round. Returns the amount won as defined in the project doc
        usize Play();

        /// The actual cost of playing the game
        static constexpr usize Cost = 2;

    private:
        /// Picks a card at random. Doesn't consider deck logic
        Card RandomCard();

        /// Draws a card from the deck
        Card DrawCard();

        /// Performs the lock/swap logic
        void LockOrSwap(Card hand_[5]);

        std::mersenne_twister_engine<std::uint_fast64_t, 64, 312, 156, 31,
                                     0xb5026f5aa96619e9, 29,
                                     0x5555555555555555, 17,
                                     0x71d67fffeda60000, 37,
                                     0xfff7eee000000000, 43, 6364136223846793005> mtEngine;
        Card mainDeck[Card::NumSuits * Card::NumValues];
        u8 cardInDeck[Card::NumSuits * Card::NumValues];
    };
}