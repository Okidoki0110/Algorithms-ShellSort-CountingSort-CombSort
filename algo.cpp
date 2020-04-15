#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include "algo.h"
using namespace std;

static unsigned nr_it;
unsigned ShellSort(std::vector<int> &input)
{
    for (int gap = (int)input.size() / 2; gap >= 1; gap /=2 ){
        for( int i = gap; i < (int) input.size(); i++) {
            for( int j = i; j >= gap; j-= gap) {
                if (input[j] < input[j-gap]) {
                    swap_shell(input, j , (j-gap));
                    nr_it++;
                } else {
                    break;
                }
            }
        }
    }   
    return nr_it;
}
 void swap_shell(std::vector<int> &vector, unsigned int i, unsigned int j) {
    int temp = vector[i];
    vector[i] = vector[j];
    vector[j] = temp;
}
