//
// Created by ASUS on 2024/4/22.
//

#include "TreeSearch.h"

TreeSearch::TreeSearch(const std::vector<int>& frameVec) : frameVector(frameVec) {}

TreeNode* TreeSearch::search(TreeNode* root) {
    TreeNode* current = root;
    for (int i : frameVector) {
        current = current->getChild(i);
        if (current == nullptr) {
            return nullptr; // Node not found
        }
    }
    return current;
}

