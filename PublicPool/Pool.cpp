// Pool.cpp

#include "Pool.h"


using namespace matching;

// 定义静态变量
PublicPool &PublicPool::getInstance() {
    static PublicPool instance;
    return instance;
}

PublicPool::PublicPool() : frameListRoot(nullptr), searchPathListRoot(nullptr), steelNumArrayListRoot(nullptr) {
    // 构造函数的其他部分
}

void PublicPool::readFrame(const struct Frame &frame) {
    const vector<int> searchPath = DataConvert::getSearchPath(frame);
    vector<int> steelNumArray = DataConvert::getSteelNumArray(frame);
    auto listID = TreeNode::search(searchPathListRoot, searchPath)->getAbsoluteID();
    steelNumArray[0]=listID;

    frameList.emplace(frame.ID, frame);
    searchPathList.emplace(frame.ID, searchPath);
    steelNumArrayList.emplace(frame.ID, steelNumArray);
    searchPathListRoot->addNode(searchPath);
    steelNumArrayListRoot->addNode(steelNumArray);
}

TreeNode* PublicPool::searchFrame(const Frame &frame) {
    const vector<int> searchPath = DataConvert::getSearchPath(frame);
    vector<int> steelNumArray = DataConvert::getSteelNumArray(frame);
    auto listID = TreeNode::search(searchPathListRoot, searchPath)->getAbsoluteID();
    steelNumArray[0]=listID;

    auto resultNodeMap = TreeNode::search(steelNumArrayListRoot, steelNumArray);

    return resultNodeMap;
}


PublicPool::~PublicPool() = default;


