#include "tests/test_range.hpp"
#include <iostream>

int main()
{
    std::vector<std::vector<int>> test_currents = {{3}, {4, 5, 4, 7, 8, 10, 9}, {5, 5, 4}};
    std::vector<std::vector<std::tuple<int, int, int>>> expected_range_list = {{std::make_tuple(3, 3, 1)}, {std::make_tuple(4, 5, 3), std::make_tuple(7, 10, 4)}, {std::make_tuple(4, 5, 3)}};

    test_range(test_currents, expected_range_list);
    std::cout << "All good!\n";
}