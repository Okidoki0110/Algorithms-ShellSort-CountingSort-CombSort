#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include "algo.h"
using namespace std;

static unsigned nr_it;
unsigned CombSort(std::vector<int> &input)
{
    float gap = input.size();
    float shrink = 1.3;
    bool sorted = false;

    while (!sorted)
    {
        gap = floor(gap / shrink);
        if (gap <= 1)
        {
            gap = 1;
            sorted = true;
        }
        size_t int_gap = (size_t)gap;
        for (size_t i = 0; i + int_gap < input.size(); i++)
        {
            if (input[i] > input[i + int_gap])
            {
                int aux = input[i];
                input[i] = input[i + int_gap];
                input[i + int_gap] = aux;
                sorted = false;
            }
            nr_it++;
        }
    }
    return nr_it;
}