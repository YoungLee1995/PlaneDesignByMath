//
// Created by ASUS on 2024/4/23.
//

#include "TestFrame.h"

Frame TestFrame::frame1 = {1, 1, 1000, 3, {
        {1, {1, STRAIGHT, 10}},
        {2, {2, STRAIGHT, 20}},
        {3, {3, STRAIGHT, 30}}
}
};

Frame TestFrame::frame2 = {13, 1, 1000, 3, {
        {1, {1, STRAIGHT, 10}},
        {2, {2, STRAIGHT, 20}},
        {3, {3, STRAIGHT, 30}}
}
};
Frame TestFrame::frame3 = {3, 1, 1000, 3, {
        {1, {1, STRAIGHT, 10}},
        {2, {2, STRAIGHT, 20}},
        {3, {3, STRAIGHT, 40}}
}
};
Frame TestFrame::frame4 = {4, 2, 1000, 3, {
        {1, {1, STRAIGHT, 10}},
        {2, {2, STRAIGHT, 20}},
        {3, {3, STRAIGHT, 30}}
}
};
Frame TestFrame::frame5 = {5, 2, 1000, 3, {
        {1, {1, STRAIGHT, 10}},
        {2, {2, STRAIGHT, 20}},
        {3, {3, STRAIGHT, 30}}
}
};
Frame TestFrame::frame6 = {6, 1, 1000, 3, {
        {1, {1, STRAIGHT, 10}},
        {2, {2, STRAIGHT, 20}},
        {3, {3, STRAIGHT, 30}}
}
};

vector<Frame> TestFrame::createTestFrames(int numFrames) {
    std::random_device rd;  // 用于获取随机数的设备
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 算法的伪随机数生成器
    std::uniform_int_distribution<> dis(0, 10000); // 定义一个均匀分布的随机数生成器
    std::uniform_int_distribution<> ton(1, 20); // 定义一个均匀分布的随机数生成器
    vector<Frame> frames;

    for (int i = 0; i < numFrames; ++i) {
        Frame frame;
        frame.ID = i;
        frame.shipTypeID = dis(gen) % 100; // 随机生成船只类型 ID
        frame.tonnage = ton(gen)*10000; // 随机生成船只吨位
        frame.edgeNum = dis(gen) % 10 + 1; // 随机生成边的数量，至少为 1

        // 为当前 Frame 生成随机边
        for (int j = 0; j < frame.edgeNum; ++j) {
            Edge edge{};
            edge.ID = j;
            edge.type = static_cast<EdgeType>(dis(gen) % 3); // 随机选择边缘类型
            edge.steelNum = dis(gen) % 100; // 随机生成钢材数量
            frame.edges[edge.ID] = edge; // 将边添加到 Frame 的 edges 映射中
        }

        frames.push_back(frame); // 将生成的 Frame 添加到列表中
    }

    return frames;
}