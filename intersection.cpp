//
// Created by Павел Пономарев on 2019-05-08.
//

#include "intersection.h"
#include <unordered_set>

size_t intersection(std::vector<int> const& first, std::vector<int> const& second) {
    std::vector<int> const& small = first.size() < second.size() ? first : second;
    std::vector<int> const& large = first.size() >= second.size() ? first : second;
    std::unordered_set<int> set(small.begin(), small.end());
    size_t result = 0;
    for (auto number: large) {
        if (result == small.size()) {
            break;
        }
        if (set.count(number) > 0) {
            ++result;
        }
    }
    return result;
}