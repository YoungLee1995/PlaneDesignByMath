//
// Created by ASUS on 2024/4/22.
//

#ifndef PLANEDESIGNBYMATH_FRAMECOMPARE_H
#define PLANEDESIGNBYMATH_FRAMECOMPARE_H
#include "../DataStruct/DataConvert.h"

using namespace matching;
using namespace std;
class FrameCompare {
public:
    static bool frameCompare(const struct Frame &frame1,const struct Frame &frame2);
    static bool arraysEqual(const vector<int> &arr1, const vector<int> &arr2);
};


#endif //PLANEDESIGNBYMATH_FRAMECOMPARE_H
