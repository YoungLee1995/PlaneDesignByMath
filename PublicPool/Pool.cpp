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
    vector<int> steelNumArray = DataConvert::getSteelNumArray(frame);
    for (int i : searchPath) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    searchPathListRoot->addNode(searchPath);
    
    auto listID = TreeNode::search(searchPathListRoot, searchPath)->getAbsoluteID();
    steelNumArray[0]=listID;    //这里是为了让搜索树2的第一层是搜索树1搜索的结果ID，以便让搜索路径从搜索树1跳转到搜索树2
    steelNumArrayListRoot->addNode(steelNumArray);
    for (int i : steelNumArray) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    frameList.emplace(frame.ID, frame);
    searchPathList.emplace(frame.ID, searchPath);
    steelNumArrayList.emplace(frame.ID, steelNumArray);
}

TreeNode* PublicPool::searchFrame(const Frame &frame) {
    const vector<int> searchPath = DataConvert::getSearchPath(frame);
    vector<int> steelNumArray = DataConvert::getSteelNumArray(frame);
    auto listID = TreeNode::search(searchPathListRoot, searchPath)->getAbsoluteID();
    steelNumArray[0]=listID;

    auto resultNodeMap = TreeNode::search(steelNumArrayListRoot, steelNumArray);

    return resultNodeMap;
}



PublicPool::PublicPool() = default;
PublicPool::~PublicPool() = default;


