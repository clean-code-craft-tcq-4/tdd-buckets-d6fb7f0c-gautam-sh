#include <assert.h>
#include <vector>
#include <tuple>
#include "detect_range.hpp"

int main()
{
    std::vector<int> current = {
        4,
        5,
        4,
        7,
        8,
        10,
        9,
    };

    std::vector<std::tuple<int, int, int>> expected_range_list = {std::make_tuple(4, 5, 3), std::make_tuple(7, 10, 4)};
    
    for (size_t i=0; i < detect_range(current).size(); ++i)
    {
        std::tuple<int, int, int> range = detect_range(current)[i];
        int front = std::get<0>(range);
        int last = std::get<1>(range);
        int count = std::get<2>(range);

        assert(front == std::get<0>(expected_range_list[i]));
        assert(last == std::get<1>(expected_range_list[i]));
        assert(count == std::get<2>(expected_range_list[i]));
    }

    generate_csv(detect_range(current));
}