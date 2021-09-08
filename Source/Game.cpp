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
        std::cout << std::endl << "Playing Double or Nothing!" << std::endl;

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
        
        // Draw card and return result
        const Card card = DrawCard();
        std::cout << "The drawn card is the " << Card::ValueStrings[card.value] << " of " << Card::SuitStrings[card.suit] << "s!" << std::endl;

        const u8 halfValues = round((f64)Card::NumValues * 0.5);
        return (card.value != halfValues) && ((lhChar == 'L' && card.value < halfValues) || (lhChar == 'H' && card.value > halfValues));
    }


    usize Game::Play()
    {
        return 4;
    }


    Card Game::DrawCard()
    {
        const u8 suit = mtEngine() % Card::NumSuits;
        const u8 value = mtEngine() % Card::NumValues;
        return mainDeck[Card::NumValues * suit + value];
    }
}