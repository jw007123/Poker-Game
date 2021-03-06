#include "Literals.h"
#include "Card.h"

#include "IOHelper.cpp"
#include "Scoring.cpp"
#include "Game.cpp"

#include <iostream>

int main()
{
    // Keep out of loop to maintain randomness
    Poker::Game theGame;

    // Determine user's pot
    usize userPot;
    std::cout << "Loading poker game! Enter starting pot amount: $";
    std::cin >> userPot;
    std::cin.clear();

    if (userPot < Poker::Game::Cost)
    {
        std::cout << "Given pot value is less than game cost at $" << Poker::Game::Cost << "! ";
        std::cout << "Setting value ot pot to be equal to $" << Poker::Game::Cost << ".";
        userPot = Poker::Game::Cost;
    }

    while (1)
    {
        std::cout << std::endl;

        // Play a game
        usize gameWinnings = theGame.Play();
        const bool hasWon = gameWinnings != 0;
        std::cout << std::endl;

        if (hasWon)
        {
            std::cout << "Congratulations! You've won $" << gameWinnings << "!" << std::endl;

            // Perform double or nothing
            while (1)
            {
                const bool playHL = Poker::HandleDecision("Attempt to double winnings", 'Y', 'N');
                if (playHL)
                {
                    const bool x2Win = theGame.DoubleOrNothing();
                    if (x2Win)
                    {
                        gameWinnings *= 2;
                        std::cout << std::endl << "Winnings doubled! New amount: $" << gameWinnings << "!" << std::endl;
                    }
                    else
                    {
                        gameWinnings = 0;
                        std::cout << std::endl << "Winnings lost... Better luck next time!" << std::endl;

                        break;
                    }
                }
                else
                {
                    // Keep pot unchanged
                    std::cout << std::endl;
                    break;
                }
            }
        }

        // Add to pot
        userPot += gameWinnings;
        if (userPot <= Poker::Game::Cost)
        {
            // Out of money
            std::cout << "Not enough money to continue... Current balance of $" << ((i32)userPot - Poker::Game::Cost) << " is less than ";
            std::cout << "the $" << Poker::Game::Cost << " price of a game. Thanks for playing!";
            break;
        }
        userPot -= Poker::Game::Cost;

        // Output current pot value and continue if user wants to play again
        std::cout << "Deducting game price of $" << Poker::Game::Cost << " from pot. Current pot amount: $" << userPot << std::endl;

        const bool playAgain = Poker::HandleDecision("Do you want to play again", 'Y', 'N');
        if (!playAgain)
        {
            break;
        }
    }

	return 0;
}