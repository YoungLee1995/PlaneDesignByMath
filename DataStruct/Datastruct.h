//
// Created by ASUS on 2024/4/7.
//

#ifndef PLANEDESIGNBYMATH_DATASTRUCT_H
#define PLANEDESIGNBYMATH_DATASTRUCT_H


#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

namespace matching {
    using namespace std;
    // 船只分类的枚举类型
    enum ShipType {
        CARGO=0,     // 货船
        TANKER=1,    // 油轮
        PASSENGER=2, // 客船
        CRUISE=3,    // 游轮
        FISHING=4    // 渔船
    };

    // 板架形状的枚举类型
    enum FrameShape {
        FLAT,
        CURVED
    };

    // 平面板的所属平面枚举类型
    enum Plane {
        XOY,
        XOZ,
        YOZ
    };

    // Edge 类型的枚举类型
    enum EdgeType {
        STRAIGHT,
        ARC_CONVEX,
        ARC_CONCAVE
    };
    // 定义 Edge 结构体
    struct Edge {
        int ID;
        EdgeType type;
        //int frameID;
        //int steelType;
        int steelNum;
        //vector<double> startPoint; // 起点的三维坐标
        //vector<double> endPoint;   // 终点的三维坐标
    };
    // 定义板架类
    struct Frame {
        int ID; // 板架ID
        //int shipID; // 所属船只ID
        int shipTypeID; // 船只类型
        int tonnage; // 船只吨位
        //FrameShape shape; // 板架形状
        //Plane plane; // 平面板的所属平面
        //int ribPosition; // 肋位
        //int ribDirection; // 肋向位置
        //int altitudeDirection; // 海拔方向位置
        int edgeNum; // 边的数量
        map<int, Edge> edges; // 存储所有 Edge 的 Map
    };

    // 定义船只类
    struct Ship {
    public:
        int shipID; // 板架所属船只ID
        ShipType type; // 船只分类
        int tonnage; //排水量
        vector<double> dimensions; // 包含长宽高的三个 double 类型数组
        double displacement; // 排水量
    };
}


#endif //PLANEDESIGNBYMATH_DATASTRUCT_H
