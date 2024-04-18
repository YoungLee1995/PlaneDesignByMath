// Pool.cpp

#include "Pool.h"

using namespace matching;

// 定义静态变量
PublicPool &PublicPool::getInstance() {
    static PublicPool instance;
    return instance;
}

// 构造函数
PublicPool::PublicPool() {
    // 进行必要的初始化
}

// 析构函数模板
template<typename T>
void clearMap(std::unordered_map<int, T *> &map) {
    for (auto &pair: map) {
        delete pair.second;
    }
    map.clear();
}

// 析构函数
PublicPool::~PublicPool() {
    clearMap(shipMap);
    clearMap(tonnageMapList);
    clearMap(edgeMapList);
    clearMap(frameMapList);
    clearMap(frameList);
}

/*void PublicPool::readFrame(struct Frame &frame) {
    auto &tonnageMapCurrent = getItem<TonnageOfSingleType>(frame.shipTypeID);
    if (tonnageMapCurrent.tonnageMap.find(frame.tonnage) != tonnageMapCurrent.tonnageMap.end()) {
        int edgeMapID=tonnageMapCurrent.tonnageMap[frame.tonnage];
        auto &edgeMapCurrent = getItem<EdgeOfSingleTon>(edgeMapID);
        if (edgeMapCurrent.edgeNumMap.find(frame.edgeNum) != edgeMapCurrent.edgeNumMap.end()) {
            int frameMapID=edgeMapCurrent.edgeNumMap[frame.edgeNum];
            auto &frameMapCurrent = getItem<FrameOfSingleEdgeNum>(frameMapID);
            int length = (int) frameList.size();
            frameList[length] = &frame;
            tonnageMapCurrent.tonnageMap[frame.tonnage] = length;
        } else {
            int length = (int) edgeMapList.size();
            auto newObj = new EdgeOfSingleTon();
            edgeMapList[length] = newObj;
            tonnageMapCurrent.tonnageMap[frame.tonnage] = length;
        }
    } else {
        int length = (int) edgeMapList.size();
        auto newObj = new EdgeOfSingleTon();
        edgeMapList[length] = newObj;
        tonnageMapCurrent.tonnageMap[frame.tonnage] = length;
    }

}*/

void PublicPool::readFrame(struct Frame &frame){
    vector<int> frameVector;
    frameVector.emplace_back(frame.shipTypeID);
    frameVector.emplace_back(frame.tonnage);
    frameVector.emplace_back(frame.edgeNum);


}
