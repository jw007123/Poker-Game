#include "IOHelper.h"

namespace Poker
{
    bool HandleDecision(const char* userMsg_, const char tChar, const char fChar)
    {
        char tfChar;
        while (1)
        {
            std::cout << userMsg_ << " [" << tChar << "/" << fChar << "]: ";
            std::cin >> tfChar;
            std::cin.clear();

            if (tfChar == tChar)
            {
                return true;
            }
            else if (tfChar == fChar)
            {
                return false;
            }
        }
    }
}