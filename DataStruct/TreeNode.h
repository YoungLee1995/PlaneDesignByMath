//
// Created by ASUS on 2024/4/18.
//

#ifndef PLANEDESIGNBYMATH_TREENODE_H
#define PLANEDESIGNBYMATH_TREENODE_H

#include <vector>
#include <unordered_map>

#include <vector>
#include <unordered_map>

class TreeNode {
public:
    explicit TreeNode(int ID);
    ~TreeNode();

    void addChild(TreeNode* child);
    TreeNode* getChild(int v);
    TreeNode* addNode(const std::vector<int>& path);
    void destroy();

private:
    int ID;
    std::unordered_map<int, TreeNode*> children;
};

#endif //PLANEDESIGNBYMATH_TREENODE_H
