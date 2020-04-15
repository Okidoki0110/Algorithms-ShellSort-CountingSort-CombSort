#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include "algo.h"
using namespace std;

static unsigned nr_it;

unsigned CountingSort(std::vector<int> &input)
{
    int max = input[0];
    int min = input[0];

    for (size_t i = 1; i < input.size(); i++)
    {
        max = input[i] > max ? input[i] : max;
        min = input[i] < min ? input[i] : min;
        nr_it++;
    }

    vector<int> frecventa(max - min + 1);
    for (auto &el : frecventa)
    {
        el = 0;
        nr_it++;
    }

    for (size_t i = 0; i < input.size(); i++)
    {
        frecventa[input[i] - min]++;
        nr_it++;
    }

    for (size_t i = 1; i < frecventa.size(); i++)
    {
        frecventa[i] = frecventa[i] + frecventa[i-1];
        nr_it++;
    }

    vector<int> sorted(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        sorted[frecventa[input[i] - min] - 1] = input[i];
        frecventa[input[i] - min]--;
        nr_it++;
    }
    input = sorted;
    
    return nr_it;
}
