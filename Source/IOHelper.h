#pragma once

#include "Literals.h"

#include <iostream>

namespace Poker
{
    /// Outputs a message of type userMsg_ [tChar/fChar]: and returns true if the user enters tChar, false if fChar
    bool HandleDecision(const char* userMsg_, const char tChar, const char fChar);
}