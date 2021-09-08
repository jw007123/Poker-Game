#include "Game.h"

namespace Poker
{
    Game::Game()
    {
        mtEngine.seed();

        for (u8 i = 0; i < Card::NumSuits; i++)
        {
            for (u8 j = 0; j < Card::NumValues; j++)
            {
                Card newCard;
                newCard.suit = i;
                newCard.value = j;

                mainDeck[Card::NumValues * i + j] = newCard;
            }
        }
    }


    Game::~Game()
    {
    }


    bool Game::DoubleOrNothing()
    {
        std::cout << std::endl << "Playing Double or Nothing! ";

        // Get user's choice
        char lhChar;
        while (1)
        {
            std::cout << "Do you think that the card will be low or high [L/H]: ";
            std::cin >> lhChar;
            std::cin.clear();
            
            if (lhChar == 'L' || lhChar == 'H')
            {
                break;
            }
        }
        
        // Pick random card and return result
        const Card card = RandomCard();
        std::cout << "The drawn card is the " << Card::ValueStrings[card.value] << " of " << Card::SuitStrings[card.suit] << "!" << std::endl;

        const u8 halfValues = round((f64)Card::NumValues * 0.5);
        return (card.value != halfValues) && ((lhChar == 'L' && card.value < halfValues) || (lhChar == 'H' && card.value > halfValues));
    }


    usize Game::Play()
    {
        std::cout << std::endl << "Playing Standard Game! Your starting hand is..." << std::endl << std::endl;

        // Reset deck
        memset(cardInDeck, 1, Card::NumSuits * Card::NumValues);

        // Draw starting hand
        Card playerHand[5];
        for (u8 i = 0; i < 5; ++i)
        {
            playerHand[i] = DrawCard();
            std::cout << Card::ValueStrings[playerHand[i].value] << " of " << Card::SuitStrings[playerHand[i].suit] << std::endl;
        }

        // Return the final score
        std::cout << std::endl;
        return ScoreHand(playerHand);
    }


    Card Game::RandomCard()
    {
        const u8 suit = mtEngine() % Card::NumSuits;
        const u8 value = mtEngine() % Card::NumValues;
        return mainDeck[Card::NumValues * suit + value];
    }


    Card Game::DrawCard()
    {
        Card newCard;
        do
        {
            newCard = RandomCard();
        } while (cardInDeck[Card::NumValues * newCard.suit + newCard.value] != 1);
        cardInDeck[Card::NumValues * newCard.suit + newCard.value] = 0;

        return newCard;
    }
}