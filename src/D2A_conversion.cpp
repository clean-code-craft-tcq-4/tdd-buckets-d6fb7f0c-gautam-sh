#include "D2A_conversion.hpp"
#include <math.h>

long int D2AConverter(int* current_bit)
{
    long int analog_current = 0;
    int size = sizeof(current_bit) / sizeof(current_bit[0]);
    for (int i = 0; i < size; ++i)
    {
        analog_current = 10 * analog_current + current_bit[i];
    }
    return analog_current;
}