//
// Created by ASUS on 2024/4/18.
//
#include "TreeNode.h"

TreeNode::TreeNode(int v) : relativeID(v) {
    counter++;
    absoluteID=counter;
    nodeMap.emplace(absoluteID,this);
}

TreeNode::~TreeNode() {
    destroy();
}

void TreeNode::addChild(TreeNode* child) {
    children[child->relativeID] = child;
}

TreeNode* TreeNode::getChild(int v) {
    auto it = children.find(v);
    if (it != children.end()) {
        return it->second;
    }
    return nullptr;
}

void TreeNode::addNode(const std::vector<int>& path) {
    TreeNode* current = this;
    for (int i : path) {
        TreeNode* child = current->getChild(i);
        if (child == nullptr) {
            child = new TreeNode(i);
            current->addChild(child);
        }
        current = child;
    }
}

void TreeNode::destroy() {
    for (auto& pair : children) {
        delete pair.second;
    }
    children.clear();
}

TreeNode *TreeNode::getNode(int absoluteID) {
    return nodeMap[absoluteID];
}

TreeNode* TreeNode::search(TreeNode* root,const std::vector<int>& frameVector) {
    TreeNode* current = root;
    for (int i : frameVector) {
        current = current->getChild(i);
        if (current == nullptr) {
            return nullptr; // Node not found
        }
    }
    return current;
}

int TreeNode::getAbsoluteID() const {
    return absoluteID;
}

