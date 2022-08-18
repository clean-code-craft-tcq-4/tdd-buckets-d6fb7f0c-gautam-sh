#include "detect_range.hpp"
#include <algorithm>
#include <tuple>
#include <fstream>

std::vector<std::tuple<int, int, int>> detect_range(std::vector<int> current)
{
    sort(current.begin(), current.end());

    std::unique(current.begin(), current.end()); // 2,3,4,5

    std::vector<std::pair<int, int>> boundary = {std::make_pair(current[0], current[0])};
    std::vector<std::tuple<int, int, int>> range_list;
    int within_range = 1;
    int front = current[0];
    int last = current[0];

    for (auto it : current)
    {
        if (it == last)
            continue;

        else if (it == (last + 1))
        {
            last = it;
            ++within_range;
        }

        else
        {
            range_list.push_back(std::make_tuple(front, last, within_range));
            front = it;
            last = it;
            within_range = 1;
        } 
    }
    range_list.push_back(std::make_tuple(front, last, within_range));

    return range_list;
}

void generate_csv(std::vector<std::tuple<int, int, int>> range_list)
{
    std::fstream range_file;
    range_file.open("range_readings.csv", std::ios::out);
    for(auto it: range_list)
    {
        range_file << std::get<0>(it) << "-" << std::get<1>(it) << ", " << std::get<2>(it) << "\n";
    }
    range_file.close();
}