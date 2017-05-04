#include "Test.h"
#include <iostream>
using namespace std;

bool isMaxHeap(int *array)
{
    int i = 0;
    while(array[i] != -1)
    {
        bool left = false;
        bool right = false;

        if(array[i*2+1] != -1)
        {
            left = array[i] < array[i*2+1];
        }

        if(array[i*2+2] != -1)
        {
            right = array[i] < array[i*2+2];
        }

        if(left || right)
            return false;
        i++;
    }
    return true;
}

int main ()
{
    test();
    return 0;
}
