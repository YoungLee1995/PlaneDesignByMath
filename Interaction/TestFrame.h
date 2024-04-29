//
// Created by ASUS on 2024/4/23.
//

#ifndef PLANEDESIGNBYMATH_TESTFRAME_H
#define PLANEDESIGNBYMATH_TESTFRAME_H


#include <ctime>
#include <random>
#include "../DataStruct/Datastruct.h"

using namespace matching;
using namespace std;

class TestFrame {
public:
    static Frame frame1;
    static Frame frame2;
    static Frame frame3;
    static Frame frame4;
    static Frame frame5;
    static Frame frame6;



    static vector<Frame> createTestFrames(int numFrames);
};


#endif //PLANEDESIGNBYMATH_TESTFRAME_H
