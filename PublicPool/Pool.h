#ifndef PLANEDESIGNBYMATH_POOL_H
#define PLANEDESIGNBYMATH_POOL_H

#include <unordered_map>
#include <mutex>
#include <stdexcept>
#include "../DataStruct/Datastruct.h"

namespace matching {

    class PublicPool {
    public:
        static PublicPool& getInstance();
        PublicPool();
        ~PublicPool();
        PublicPool(const PublicPool&) = delete;
        PublicPool& operator=(const PublicPool&) = delete;

        static void readFrame(const struct Frame& frame);

    private:
        mutable std::unordered_map<int, Ship&> shipMap; //key:顺序ID
        mutable std::unordered_map<int, FrameOfSingleEdgeNum&> frameMapList;       //key:顺序ID
        mutable std::unordered_map<int, Frame&> frameList;           //key:顺序ID
        mutable std::mutex mutex_;
    };


} // namespace matching

#endif //PLANEDESIGNBYMATH_POOL_H
