//
// Created by ASUS on 2024/4/22.
//

#ifndef PLANEDESIGNBYMATH_DATACONVERT_H
#define PLANEDESIGNBYMATH_DATACONVERT_H

#include <vector>
#include "Datastruct.h"

namespace matching {
    using namespace std;

    class DataConvert {
    public:
        static vector<int> getSearchPath(const struct Frame &frame);
        static vector<int> getSteelNumArray(const struct Frame &frame);
    };
}


#endif //PLANEDESIGNBYMATH_DATACONVERT_H
