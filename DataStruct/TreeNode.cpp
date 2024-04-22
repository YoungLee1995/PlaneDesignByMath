//
// Created by ASUS on 2024/4/18.
//
#include "TreeNode.h"

TreeNode::TreeNode(int v) : ID(v) {}

TreeNode::~TreeNode() {
    destroy();
}

void TreeNode::addChild(TreeNode* child) {
    children[child->ID] = child;
}

TreeNode* TreeNode::getChild(int v) {
    auto it = children.find(v);
    if (it != children.end()) {
        return it->second;
    }
    return nullptr;
}

TreeNode* TreeNode::addNode(const std::vector<int>& path) {
    TreeNode* current = this;
    for (int i : path) {
        TreeNode* child = current->getChild(i);
        if (child == nullptr) {
            child = new TreeNode(i);
            current->addChild(child);
        }
        current = child;
    }
    return current;
}

void TreeNode::destroy() {
    for (auto& pair : children) {
        delete pair.second;
    }
    children.clear();
}

