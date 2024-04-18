//
// Created by ASUS on 2024/4/18.
//

#ifndef PLANEDESIGNBYMATH_TREENODE_H
#define PLANEDESIGNBYMATH_TREENODE_H


#include <unordered_map>

class TreeNode {
public:
    int val;
    std::unordered_map<int, TreeNode*> children;

    TreeNode(int v);
    void addChild(TreeNode* child);
    TreeNode* getChild(int v);
};


#endif //PLANEDESIGNBYMATH_TREENODE_H
