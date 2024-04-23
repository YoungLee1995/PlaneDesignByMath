//
// Created by ASUS on 2024/4/18.
//

#ifndef PLANEDESIGNBYMATH_TREENODE_H
#define PLANEDESIGNBYMATH_TREENODE_H

#include <vector>
#include <unordered_map>
#include <map>
class TreeNode {
public:
    explicit TreeNode(int ID);
    ~TreeNode();

    static TreeNode* getNode(int absoluteID);
    static TreeNode* search(TreeNode* root,const std::vector<int>& frameVector);
    TreeNode* getChild(int v);
    void addNode(const std::vector<int>& path);
    void addChild(TreeNode* child);
    void destroy();

private:
    static int counter;
    static std::map<int,TreeNode*> nodeMap;
    int absoluteID;
    int relativeID;
    std::unordered_map<int, TreeNode*> children;
};

#endif //PLANEDESIGNBYMATH_TREENODE_H
