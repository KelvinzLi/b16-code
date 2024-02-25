#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    // WRITE YOUR CODE HERE
    bool flag = false;
    T tree_ptr = tree;

    while (!flag) {
        T left_ptr = left(tree_ptr);
        T right_ptr = right(tree_ptr);

        if ((bool)left_ptr & (bool)right_ptr) {
            if (value(left_ptr) > value(right_ptr)) {
                tree_ptr = right_ptr;
            }
            else {
                tree_ptr = left_ptr;
            }
        }
        else if ((bool)left_ptr | (bool)right_ptr)
        {
            if (right_ptr) {
                tree_ptr = right_ptr;
            }
            else {
                tree_ptr = left_ptr;
            }
        }
        else {
            flag = true;
        } 
    }

    return tree_ptr;
}

template <typename T> T bst_max(const T &tree)
{
    // WRITE YOUR CODE HERE
    bool flag = false;
    T tree_ptr = tree;

    while (!flag) {
        T left_ptr = left(tree_ptr);
        T right_ptr = right(tree_ptr);

        if ((bool)left_ptr & (bool)right_ptr) {
            if (value(left_ptr) < value(right_ptr)) {
                tree_ptr = right_ptr;
            }
            else {
                tree_ptr = left_ptr;
            }
        }
        else if ((bool)left_ptr | (bool)right_ptr)
        {
            if (right_ptr) {
                tree_ptr = right_ptr;
            }
            else {
                tree_ptr = left_ptr;
            }
        }
        else {
            flag = true;
        } 
    }

    return tree_ptr;
}

#endif // __binary_saerch_tree_enhanced__