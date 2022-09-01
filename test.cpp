#include <assert.h>
#include <vector>
#include <tuple>
#include "detect_range.hpp"
#include <iostream>

int main()
{
    std::vector<std::vector<int>> test_currents = {{3}, {4, 5, 4, 7, 8, 10, 9}, {5, 5, 4}};

    std::vector<std::vector<std::tuple<int, int, int>>> expected_range_list = {{std::make_tuple(3, 3, 1)}, {std::make_tuple(4, 5, 3), std::make_tuple(7, 10, 4)}, {std::make_tuple(4, 5, 3)}};

    for (size_t j = 0; j < test_currents.size(); ++j)
    {
        for (size_t i = 0; i < detect_range(test_currents[j]).size(); ++i)
        {
            std::tuple<int, int, int> range = detect_range(test_currents[j])[i];
            int front = std::get<0>(range);
            int last = std::get<1>(range);
            int count = std::get<2>(range);

            assert(front == std::get<0>(expected_range_list[j][i]));
            assert(last == std::get<1>(expected_range_list[j][i]));
            assert(count == std::get<2>(expected_range_list[j][i]));
        }
        generate_csv(detect_range(test_currents[j]));
    }
    std::cout << "All good!\n";
}