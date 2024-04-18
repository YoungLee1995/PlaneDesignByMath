#ifndef PLANEDESIGNBYMATH_POOL_H
#define PLANEDESIGNBYMATH_POOL_H

#include <unordered_map>
#include <mutex>
#include <stdexcept>
#include "../Interaction/Datastruct.h"

namespace matching {

    class PublicPool {
    public:
        static PublicPool& getInstance();

        PublicPool();
        ~PublicPool();
        PublicPool(const PublicPool&) = delete;
        PublicPool& operator=(const PublicPool&) = delete;

        void readFrame(Frame& frame);


        template<typename T>
        T& getItem(int id) const {
            std::lock_guard<std::mutex> lock(mutex_);
            auto it = itemMap<T>().find(id);
            if (it == itemMap<T>().end()) {
                std::cerr << "Warning: ItemMap does not contain the specified ID. Creating a new object." << std::endl;
                // Create a new object and insert it into itemMap
                auto newObj = new T(); // Assuming T has a default constructor
                itemMap<T>()[id] = newObj;
                return *newObj;
            }
            return *(it->second);
        }

        template<typename T>
        bool containsItem(int id) const {
            std::lock_guard<std::mutex> lock(mutex_);
            return itemMap<T>().find(id) != itemMap<T>().end();
        }

        template<typename T>
        void addItem(int id, const T &item) {
            std::lock_guard<std::mutex> lock(mutex_);
            itemMap<T>()[id] = new T(item);
        }

        template<typename T>
        void releaseItem(int id) {
            std::lock_guard<std::mutex> lock(mutex_);
            auto it = itemMap<T>().find(id);
            if (it != itemMap<T>().end()) {
                delete it->second;
                itemMap<T>().erase(it);
            }
        }

    private:
        template<typename T>
        std::unordered_map<int, T*>& itemMap() const;

        mutable std::unordered_map<int, Ship*> shipMap; //key:顺序ID
        mutable std::unordered_map<int, TonnageOfSingleType*> tonnageMapList;  //key:顺序ID
        mutable std::unordered_map<int, EdgeOfSingleTon*> edgeMapList;    //key:顺序ID
        mutable std::unordered_map<int, FrameOfSingleEdgeNum*> frameMapList;       //key:顺序ID
        mutable std::unordered_map<int, Frame*> frameList;           //key:顺序ID
        mutable std::mutex mutex_;
    };

// Template specializations
    template<>
    std::unordered_map<int, Ship *>& PublicPool::itemMap<Ship>() const {
        return shipMap;
    }

    template<>
    std::unordered_map<int, TonnageOfSingleType *>& PublicPool::itemMap<TonnageOfSingleType>() const {
        return tonnageMapList;
    }

    template<>
    std::unordered_map<int, EdgeOfSingleTon *>& PublicPool::itemMap<EdgeOfSingleTon>() const {
        return edgeMapList;
    }

    template<>
    std::unordered_map<int, FrameOfSingleEdgeNum *>& PublicPool::itemMap<FrameOfSingleEdgeNum>() const {
        return frameMapList;
    }

    template<>
    std::unordered_map<int, Frame *>& PublicPool::itemMap<Frame>() const {
        return frameList;
    }

} // namespace matching

#endif //PLANEDESIGNBYMATH_POOL_H
