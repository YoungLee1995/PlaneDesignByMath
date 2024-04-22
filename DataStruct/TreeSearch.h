//
// Created by ASUS on 2024/4/22.
//

#ifndef PLANEDESIGNBYMATH_TREESEARCH_H
#define PLANEDESIGNBYMATH_TREESEARCH_H

#include "TreeNode.h"
#include <vector>

class TreeSearch {
public:
    explicit TreeSearch(const std::vector<int>& frameVec);
    TreeNode* search(TreeNode* root);

private:
    std::vector<int> frameVector;
};
#endif //PLANEDESIGNBYMATH_TREESEARCH_H
