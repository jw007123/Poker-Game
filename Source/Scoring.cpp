#include "Scoring.h"

namespace Poker
{
    bool FindPair(const Card hand_[5])
    {
        for (u8 i = 0; i < 5; ++i)
        {
            for (u8 j = i + 1; j < 5; ++j)
            {
                if (hand_[i].value == hand_[j].value)
                {
                    return true;
                }
            }
        }

        return false;
    }


    bool FindTwoPair(const Card hand_[5])
    {
        u8 nPairs = 0;
        for (u8 i = 0; i < 5; ++i)
        {
            for (u8 j = i + 1; j < 5; ++j)
            {
                if (hand_[i].value == hand_[j].value)
                {
                    nPairs += 1;
                }
            }
        }

        return nPairs == 2;
    }


    bool FindThreeOfAKind(const Card hand_[5])
    {
        for (u8 i = 0; i < 5; ++i)
        {
            for (u8 j = i + 1; j < 5; ++j)
            {
                for (u8 k = i + j + 1; k < 5; ++k)
                {
                    // Transitive property
                    if (hand_[i].value == hand_[j].value && 
                        hand_[j].value == hand_[k].value)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }


    bool FindFullHouse(const Card hand_[5])
    {
        return FindThreeOfAKind(hand_) && FindPair(hand_);
    }


    bool FindStraight(const Card hand_[5])
    {
        Card sortedHand[5];
        for (u8 i = 0; i < 5; ++i)
        {
            sortedHand[i] = hand_[i];
        }

        auto CompFunc = [](const void* x_, const void* y_) -> i16
        {
            const Card& x = *(Card*)x_;
            const Card& y = *(Card*)y_;

            if (x.value < y.value) return -1;
            if (x.value > y.value) return 1;
            return 0;
        };
        std::qsort(sortedHand, 5, sizeof(Card), CompFunc);

        for (u8 i = 0; i < 4; ++i)
        {
            if ((sortedHand[i].value + 1) != sortedHand[i + 1].value)
            {
                return false;
            }
        }

        return true;
    }


    bool FindFourOfAKind(const Card hand_[5])
    {
        for (u8 i = 0; i < 5; ++i)
        {
            for (u8 j = i + 1; j < 5; ++j)
            {
                for (u8 k = i + j + 1; k < 5; ++k)
                {
                    for (u8 l = i + j + k + 1; l < 5; ++l)
                    {
                        // Transitive property
                        if (hand_[i].value == hand_[j].value && 
                            hand_[j].value == hand_[k].value &&
                            hand_[k].value == hand_[l].value)
                        {
                            return true;
                        }
                    }
                   
                }
            }
        }

        return false;
    }


    usize ScoreHand(const Card hand_[5])
    {
        bool(*FindFuncs[6]) (const Card hand[5]) =
        {
            FindFourOfAKind,
            FindStraight,
            FindFullHouse,
            FindThreeOfAKind,
            FindTwoPair,
            FindPair
        };

        u8 Scores[6] = 
        {
            12,
            10,
            8,
            6,
            4,
            2
        };

        const char* ScoreStrings[6] = 
        {
            "Four of a Kind",
            "Straight",
            "Full House",
            "Three of a Kind",
            "Two Pairs",
            "Single Pair"
        };

        for (u8 i = 0; i < 6; ++i)
        {
            if ((*FindFuncs[i])(hand_))
            {
                std::cout << "The deck has a " << ScoreStrings[i] << "!" << std::endl;
                return Scores[i];
            }
        }

        std::cout << "No winning combinations in the deck!" << std::endl;
        return 0;
    }
}