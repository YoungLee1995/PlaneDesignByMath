//
// Created by ASUS on 2024/4/22.
//

#include "MainWindow.h"

int MainWindow::main() {
    std::cout << "Hello, World!1111" << std::endl;
    pool.readFrame(TestFrame::frame1);
    pool.readFrame(TestFrame::frame2);
    pool.readFrame(TestFrame::frame3);
    pool.readFrame(TestFrame::frame4);
    pool.readFrame(TestFrame::frame5);
    TreeNode* tree= pool.searchFrame(TestFrame::frame2);
    std::cout << tree->getRelativeId() << std::endl;
    return 0;
}
