//
// Created by ASUS on 2024/4/22.
//

#include "DataConvert.h"

std::vector<int> matching::DataConvert::getSearchPath(const struct Frame &frame) {
    vector<int> result;
    result.emplace_back(frame.shipTypeID);
    result.emplace_back(frame.tonnage);
    result.emplace_back(frame.edgeNum);
    result.emplace_back(frame.ID);
    return result;
}

std::vector<int> matching::DataConvert::getSteelNumArray(const struct Frame &frame) {
    vector<int> result;
    result.reserve(frame.edges.size()+1);
    result.emplace_back(0); //后续队首需要插入当前所属的edgeMap的ID，在此预留
    for (const auto &edge: frame.edges) {
        result.emplace_back(edge.second.steelNum);
    }
    result.emplace_back(frame.ID);
    return result;
}
