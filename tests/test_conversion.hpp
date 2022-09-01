#include "detect_range.hpp"
#include <vector>
#include <assert.h>

void test_conversion(std::vector<int*> current_bit,std::vector<int> current)
{
    for(size_t i = 0; i < current_bit.size(); ++i)
    {
        assert(current[i] == D2AConverter(current_bit[i]));
    }
}