#include "Literals.h"
#include "Card.h"

#include "Game.cpp"

#include <iostream>

int main()
{
    // Keep out of loop to maintain randomness
    Poker::Game theGame;

    // Determine user's pot
    usize userPot;
    std::cout << " Loading poker game! Enter starting pot amount: ";
    std::cin >> userPot;
    std::cin.clear();

    if (userPot < theGame.GetGameCost())
    {
        std::cout << "Given pot value is less than game cost at $" << theGame.GetGameCost() << "! ";
        std::cout << "Setting value ot pot to be equal to $" << theGame.GetGameCost() << ".";
        userPot = theGame.GetGameCost();
    }

    while (1)
    {
        std::cout << std::endl << std::endl;

        // Play a game
        usize gameWinnings = theGame.Play();
        const bool hasWon = gameWinnings != 0;

        if (hasWon)
        {
            std::cout << "Congratulations! You've won $" << gameWinnings << "!" << std::endl;

            // Perform double or nothing
            while (1)
            {
                char ynChar;
                std::cout << "Attempt to double winnings [Y/N]: ";
                std::cin >> ynChar;
                std::cin.clear();

                if (ynChar == 'Y')
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
                else if (ynChar == 'N')
                {
                    // Keep pot unchanged
                    std::cout << std::endl;
                    break;
                }
            }
        }

        // Add to pot
        userPot += gameWinnings;
        if (userPot <= theGame.GetGameCost())
        {
            // Out of money
            std::cout << "Not enough money to continue... Current balance of $" << ((i16)userPot - 2) << " is less than ";
            std::cout << "the $" << theGame.GetGameCost() << " price of a game. Thanks for playing!";
            break;
        }
        userPot -= theGame.GetGameCost();

        // Output current pot value and continue if user wants to play again
        std::cout << "Deducting game price of $" << theGame.GetGameCost() << " from pot. Current pot amount: $" << userPot << std::endl;
        bool gameOver = false;
        while (1)
        {
            char ynChar;
            std::cout << "Do you want to play again [Y/N]: ";
            std::cin >> ynChar;
            std::cin.clear();

            if (ynChar == 'Y')
            {
                break;
            }
            else if (ynChar == 'N')
            {
                gameOver = true;
                break;
            }
        }
      
        if (gameOver)
        {
            break;
        }
    }

    
	return 0;
}