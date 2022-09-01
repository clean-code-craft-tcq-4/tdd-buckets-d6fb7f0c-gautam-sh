#include "tests/test_range.hpp"
#include "tests/test_conversion.hpp"
#include <iostream>

int main()
{
    // Testing range detection
    std::cout << "1. Testing range detection\n";
    std::vector<std::vector<int>> test_currents = {{3}, {4, 5, 4, 7, 8, 10, 9}, {5, 5, 4}};
    std::vector<std::vector<std::tuple<int, int, int>>> expected_range_list = {{std::make_tuple(3, 3, 1)}, {std::make_tuple(4, 5, 3), std::make_tuple(7, 10, 4)}, {std::make_tuple(4, 5, 3)}};

    test_range(test_currents, expected_range_list);
    std::cout << "Range detection tested successfully\n";

    std::cout << "2. Testing D2A conversion/n";
    int bit[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    std::vector<int*> test_current_bit{bit};
    std::vector<long int> test_current{10};
    test_conversion(test_current_bit, test_current);
    std::cout << "D2A conversion tested successfully\n";

    std::cout << "All good!\n";
}