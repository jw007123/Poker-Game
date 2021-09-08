#pragma once

#include "Literals.h"
#include "Card.h"

#include <cstdlib>
#include <iostream>

namespace Poker
{
    /// Returns the $ equivalent of a user's hand
    usize ScoreHand(const Card hand_[5]);

    /// Determines whether various patterns exist in a hand
    bool FindPair(const Card hand_[5]);
    bool FindTwoPair(const Card hand_[5]);
    bool FindThreeOfAKind(const Card hand_[5]);
    bool FindFullHouse(const Card hand_[5]);
    bool FindStraight(const Card hand_[5]);
    bool FindFourOfAKind(const Card hand_[5]);
}