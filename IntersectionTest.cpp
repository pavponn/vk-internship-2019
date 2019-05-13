//
// Created by Павел Пономарев on 2019-05-09.
//

#include "IntersectionTest.h"
#include "intersection.h"
#include <iostream>
#include <random>
#include <unordered_set>

IntersectionTest::IntersectionTest() : mAllPassed(true) {}

bool IntersectionTest::runTests() {
    mAllPassed = emptyTests()
               & equalTests()
               & subsetTests()
               & distinctTests()
               & commonTests()
               & randomTests();

    printResultMessage(mAllPassed ? "PASSED " : "FAILED");
    return mAllPassed;
}

bool IntersectionTest::emptyTests() {
    const size_t TESTS_NUM = 3;
    size_t testsPassed = 0;
    std::vector<int> vector = {1, 2, 3, 4, 5};

    printRunTestMessage("emptyTests");

    testsPassed += checkAnswer(intersection({}, {}), 0) ? 1 : 0;

    testsPassed += checkAnswer(intersection(vector, {}), 0) ? 1 : 0;

    testsPassed += checkAnswer(intersection({}, vector), 0) ? 1 : 0;

    printTestsPassedMessage(testsPassed, TESTS_NUM);
    return testsPassed == TESTS_NUM;
}

bool IntersectionTest::equalTests() {
    const size_t TESTS_NUM = 6;
    size_t testsPassed = 0;
    std::vector<int> first = {1, 2, 3, 4, 5, 6, 7}, second = {6, 5, 3, 4, 1, 2, 7};

    printRunTestMessage("equalTests");

    testsPassed += checkAnswer(intersection(first, first), first.size()) ? 1 : 0;
    
    testsPassed += checkAnswer(intersection(first, second), first.size()) ? 1 : 0;

    first = getRandomVector(20, 100);
    testsPassed += checkAnswer(intersection(first, first), first.size()) ? 1 : 0;

    first = getRandomVector(40, 100);
    testsPassed += checkAnswer(intersection(first, first), first.size()) ? 1 : 0;

    first = getRandomVector(10000, 300000);
    testsPassed += checkAnswer(intersection(first, first), first.size()) ? 1 : 0;

    testsPassed += checkAnswer(intersection({1}, {1}), 1) ? 1 : 0;

    printTestsPassedMessage(testsPassed, TESTS_NUM);
    return testsPassed == TESTS_NUM;
}

bool IntersectionTest::subsetTests() {
    const size_t TESTS_NUM = 7;
    size_t testsPassed = 0;

    printRunTestMessage("subsetTests");

    testsPassed += checkAnswer(intersection({1}, {1, 10}), 1) ? 1 : 0;

    testsPassed += checkAnswer(intersection({1, 2, 3, 4}, {1, 4}), 2) ? 1 : 0;

    testsPassed += checkAnswer(intersection({3, 23, 311, 413, 24, 42, 789}, {1, 3, 23, 311, 413, 24, 42, 789, 4}), 7)
                   ? 1 : 0;

    testsPassed += checkAnswer(intersection({22, 11, 17, 34, 18}, {34, 11, 18}), 3) ? 1 : 0;

    testsPassed += checkAnswer(intersection({267, 0, -7, -45, 1890, -6, 45}, {267, 0, 1890, -6, -7}), 5) ? 1 : 0;

    testsPassed += checkAnswer(intersection({11, 14, 2}, {-2, 0, 2, 19501, 14, 79, 89, 72, 11}), 3) ? 1 : 0;

    testsPassed += checkAnswer(intersection({232, 1111, 239293, 67, 353, 44, -1242, 0}, {-1242, 1111}), 2) ? 1 : 0;

    printTestsPassedMessage(testsPassed, TESTS_NUM);
    return testsPassed == TESTS_NUM;
}

bool IntersectionTest::distinctTests() {
    const size_t TESTS_NUM = 5;
    size_t testsPassed = 0;

    printRunTestMessage("distinctTests");

    testsPassed += checkAnswer(intersection({1}, {2, 10}), 0) ? 1 : 0;

    testsPassed += checkAnswer(intersection({1, 2, 3, 4}, {6, 5}), 0) ? 1 : 0;

    testsPassed += checkAnswer(intersection({3, 23, 311, 413, 24, 42, 789}, {121, 1, 73, 11, 0, 2540, 987, 300, 14}), 0)
                   ? 1 : 0;

    testsPassed += checkAnswer(intersection({22, 11, 17, 34, 18}, {321, -511, 2047}), 0) ? 1 : 0;

    testsPassed += checkAnswer(intersection({267, 0, -7, -45, 1890, -6, 45}, {-1422, 76, 197, -9, -88}), 0) ? 1 : 0;

    printTestsPassedMessage(testsPassed, TESTS_NUM);
    return testsPassed == TESTS_NUM;
}

bool IntersectionTest::commonTests() {
    const size_t TESTS_NUM = 4;
    size_t testsPassed = 0;

    printRunTestMessage("commonTests");

    testsPassed += checkAnswer(intersection({132, 145, 432, 0, -77321, 3435, 22, 11, 232145, 435535, -2313},
                                            {22, 14, 66, 77, -3451, 89, 232145, 0, -77321}), 4) ? 1 : 0;

    testsPassed += checkAnswer(intersection({54503, 69436, 11385, 22, 371, 674, 9863, 289923, 2123, -34432},
                                            {22, 14, 66, 54503, -3451, 89, 371, -2423213}), 3) ? 1 : 0;

    testsPassed += checkAnswer(intersection({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {9, 8, 7, 32, 34, 657, 6, 5, 123}), 5) ? 1
                                                                                                                    : 0;

    testsPassed += checkAnswer(intersection({-6263858, 3525255, 53575, 1000000232, 65757, 343, 464303, -28096, 3530525},
                                            {353523, 3530525, 53575, 33535, 0, 343, 53505, -626385, -28096, 464604646,
                                             104374, 65757,
                                             78952}), 5) ? 1 : 0;


    printTestsPassedMessage(testsPassed, TESTS_NUM);
    return testsPassed == TESTS_NUM;
}

bool IntersectionTest::randomTests() {
    const size_t TESTS_NUM = 500;
    size_t testsPassed = 0;
    std::vector<int> first, second;

    printRunTestMessage("randomTests");

    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());
    std::uniform_int_distribution<size_t> sizeDistribution(1, 1000);
    std::uniform_int_distribution<size_t> multiplierDistribution(2, 10);

    for (size_t i = 0; i < TESTS_NUM; ++i) {
        auto firstSize = sizeDistribution(mt);
        auto secondSize = sizeDistribution(mt);

        first = getRandomVector(firstSize, static_cast<int>(firstSize * multiplierDistribution(mt)));
        second = getRandomVector(secondSize, static_cast<int>(secondSize * multiplierDistribution(mt)));

        testsPassed += checkAnswer(intersection(first, second), simpleIntersection(first, second)) ? 1 : 0;
    }
    printTestsPassedMessage(testsPassed, TESTS_NUM);
    return testsPassed == TESTS_NUM;
}


std::vector<int> IntersectionTest::getRandomVector(size_t size, int range) {
    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());
    std::uniform_int_distribution<int> dist(-range, range);
    std::unordered_set<int> randomNumbers;
    while (randomNumbers.size() < size) {
        randomNumbers.insert(dist(mt));
    }
    std::vector<int> result;
    result.insert(result.end(), randomNumbers.begin(), randomNumbers.end());
    return result;
}

size_t IntersectionTest::simpleIntersection(std::vector<int> const& first, std::vector<int> const& second) {
    size_t result = 0;
    for (auto inFirst : first) {
        for (auto inSecond : second) {
            if (inFirst == inSecond) {
                ++result;
                break;
            }
        }
    }
    return result;
}

bool IntersectionTest::checkAnswer(size_t result, size_t expected) {
    return expected == result;
}

void IntersectionTest::printTestsPassedMessage(size_t passed, const size_t ALL) {
    std::cout << "======== TESTS PASSED " << passed << " OUT OF " << ALL << " ========" << std::endl;
}

void IntersectionTest::printRunTestMessage(std::string const& testsName) {
    std::cout << "Running " << testsName << "..." << std::endl;
}

void IntersectionTest::printResultMessage(std::string const& result) {
    std::cout << "TESTS " << result << std::endl;
}
