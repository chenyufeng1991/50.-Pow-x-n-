//
//  main.cpp
//  50. Pow(x, n)
//
//  Created by chenyufeng on 10/6/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double myPow(double x, int n)
{
    bool isFlow = false;
    if(x == 1.0)
    {
        return 1.0;
    }

    if (x == -1.0)
    {
        if (n % 2 == 0)
        {
            return 1.0;
        }
        else
        {
            return -1.0;
        }
    }

    if (n == -2147483648)
    {
        n = -2147483647;
        isFlow = true;
    }

    double result = 1.0;
    int absN = n >= 0 ? n : -n;
    for (int i = 0; i < absN; i++)
    {
        result *= x;
        if (n >= 0)
        {
            if(fabs(result) < 0.00001 && fabs(result) > 0)
            {
                return 0.00000;
            }
        }
        else
        {
            if(fabs(1/result) < 0.00001 && fabs(1/result) > 0)
            {
                return 0.00000;
            }
        }
    }

    if (isFlow)
    {
        result *= x;
    }

    return n >= 0 ? result : 1/result;
}

/**
 *  -1.00000
 2147483647
 */
int main(int argc, const char * argv[])
{
    double res = myPow(2.00000, -2147483648);
    cout << res;

    return 0;
}
