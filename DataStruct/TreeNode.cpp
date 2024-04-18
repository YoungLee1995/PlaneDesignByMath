//
// Created by ASUS on 2024/4/18.
//

#include "TreeNode.h"

TreeNode::TreeNode(int v) : val(v) {}

void TreeNode::addChild(TreeNode* child) {
    children[child->val] = child;
}

TreeNode* TreeNode::getChild(int v) {
    auto it = children.find(v);
    if (it != children.end()) {
        return it->second;
    }
    return nullptr;
}
