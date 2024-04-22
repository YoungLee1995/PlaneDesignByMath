//
// Created by ASUS on 2024/4/22.
//

#include "FrameCompare.h"

bool FrameCompare::frameCompare(const Frame &frame1, const Frame &frame2) {
    return arraysEqual(DataConvert::getSteelNumArray(frame1), DataConvert::getSteelNumArray(frame2));
}

bool FrameCompare::arraysEqual(const std::vector<int> &arr1, const std::vector<int> &arr2) {
    if (arr1.size() != arr2.size()) {
        return false; // 数组长度不同，直接返回false
    }

    for (size_t i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            return false; // 如果对应位置的元素不相同，则返回false
        }
    }

    return true; // 数组完全相同
}