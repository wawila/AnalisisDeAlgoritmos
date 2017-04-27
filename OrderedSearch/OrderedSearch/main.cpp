#include "Test.h"
#include <iostream>
using namespace std;

bool numberExistsAux(vector<int> ordered_numbers, int x, int begin, int end)
{
    int current = begin + (end - begin)/2;

    if(ordered_numbers[current] == x)
    {
        return true;
    }

    if(ordered_numbers[current+1] > x && ordered_numbers[current-1] < x)
        return false;

    if(current >= 0 && ordered_numbers[current] > x)
    {
        return numberExistsAux(ordered_numbers, x, begin, current);
    }

    if(current <= ordered_numbers.size() && ordered_numbers[current] < x)
    {
        return numberExistsAux(ordered_numbers, x, current, end);
    }

    return false;

}

bool numberExists(vector<int> ordered_numbers, int x)
{
    return numberExistsAux(ordered_numbers, x, 0, ordered_numbers.size());
}


int main ()
{
    test();
    return 0;
}
