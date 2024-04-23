// Pool.cpp

#include "Pool.h"


using namespace matching;

// 定义静态变量
PublicPool &PublicPool::getInstance() {
    static PublicPool instance;
    return instance;
}

void PublicPool::readFrame(const struct Frame &frame) {
    const vector<int> searchPath = DataConvert::getSearchPath(frame);
    const vector<int> steelNumArray = DataConvert::getSteelNumArray(frame);

    frameList.emplace(frame.ID, frame);
    searchPathList.emplace(frame.ID, searchPath);
    steelNumArrayList.emplace(frame.ID, steelNumArray);
    searchPathListRoot->addNode(searchPath);
    steelNumArrayListRoot->addNode(steelNumArray);
}

int PublicPool::searchFrame(const Frame &frame) {
    const vector<int> searchPath = DataConvert::getSearchPath(frame);
    const vector<int> steelNumArray = DataConvert::getSteelNumArray(frame);

    //int listID= searchPathListRoot->getChild(searchPath);
    steelNumArrayListRoot->addNode(steelNumArray);
    return 0;
}

PublicPool::PublicPool() = default;

PublicPool::~PublicPool() = default;


