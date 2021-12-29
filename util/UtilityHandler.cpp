//
//  UtilityHandler.cpp
//  MatchScheduler
//
//  Created by Vishnu Balasubramanian on 29/12/21.
//

#include "UtilityHandler.hpp"

int Util::CalculateFactorial(int num)
{
    if(num >= 1)
        return num * CalculateFactorial(num-1);
    else
        return 1;
}
