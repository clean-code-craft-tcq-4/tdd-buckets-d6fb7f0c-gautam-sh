#include <assert.h>
#include <vector>
#include <tuple>
#include "detect_range.hpp"

void test_range(std::vector<std::vector<int>> test_currents, std::vector<std::vector<std::tuple<int, int, int>>> expected_range_list)
{
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
}