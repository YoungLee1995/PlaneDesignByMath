#ifndef PLANEDESIGNBYMATH_POOL_H
#define PLANEDESIGNBYMATH_POOL_H

#include <unordered_map>
#include <mutex>
#include <stdexcept>
#include <memory>
#include "../DataStruct/Datastruct.h"
#include "../DataStruct/DataConvert.h"
#include "../DataStruct/TreeNode.h"

namespace matching {

    class PublicPool {
    public:
        static PublicPool& getInstance();
        PublicPool();
        ~PublicPool();
        PublicPool(const PublicPool&) = delete;
        PublicPool& operator=(const PublicPool&) = delete;

        void readFrame(const struct Frame& frame);
        int searchFrame(const struct Frame& frame);

    private:
        std::unordered_map<int, Ship&> shipMap; //key:顺序ID
        std::unordered_map<int, const std::vector<int>&> frameIDMapList;       //key:顺序ID
        std::unordered_map<int, const std::vector<int>&> steelNumArrayList;       //key:顺序ID
        std::unordered_map<int, const std::vector<int>&> searchPathList;       //key:顺序ID
        std::unordered_map<int, const struct Frame&> frameList;           //key:顺序ID
        std::mutex mutex_;
        TreeNode* frameListRoot{};
        TreeNode* searchPathListRoot{};
        TreeNode* steelNumArrayListRoot{};
    };


} // namespace matching

#endif //PLANEDESIGNBYMATH_POOL_H
