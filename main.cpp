//
// Created by Павел Пономарев on 2019-05-08.
//

#include <iostream>
#include <vector>
#include "IntersectionTest.h"

int main() {
    IntersectionTest test;
    if (test.runTests()) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}