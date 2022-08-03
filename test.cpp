#include <assert.h>
#include <vector>

int main() {
    std::vector<int> current(4,5);
    assert(detect_range(current)=="4-5,2");
}