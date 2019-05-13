//
// Created by Павел Пономарев on 2019-05-09.
//

#ifndef VK_INTERNSHIP_INTERSECTIONTEST_H
#define VK_INTERNSHIP_INTERSECTIONTEST_H

#include <vector>
#include <string>

class IntersectionTest {
public:
    IntersectionTest();
    bool runTests();

private:
    bool emptyTests();
    bool equalTests();
    bool subsetTests();
    bool distinctTests();
    bool commonTests();
    bool randomTests();

    bool checkAnswer(size_t, size_t);
    void printRunTestMessage(std::string const&);
    void printTestsPassedMessage(size_t, size_t);
    void printResultMessage(std::string const&);

    std::vector<int> getRandomVector(size_t, int);

    size_t simpleIntersection(std::vector<int> const&, std::vector<int> const&);

    bool mAllPassed;
};


#endif //VK_INTERNSHIP_INTERSECTIONTEST_H
