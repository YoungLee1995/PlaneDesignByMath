// Pool.cpp

#include "Pool.h"

using namespace matching;

// 定义静态变量
PublicPool &PublicPool::getInstance() {
    static PublicPool instance;
    return instance;
}

void PublicPool::readFrame(const struct Frame& frame) {

}

PublicPool::PublicPool() = default;
PublicPool::~PublicPool() = default;


