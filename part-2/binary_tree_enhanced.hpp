#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <vector>
#include <memory>

// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    std::unique_ptr<BinaryTreeEnhanced<V>> _left;
    std::unique_ptr<BinaryTreeEnhanced<V>> _right;

    // WRITE YOUR CODE HERE
    BinaryTreeEnhanced<V>* _parent;

    void setParent(BinaryTreeEnhanced<V>* parent) {
        _parent = parent;
    }

    // BinaryTreeEnhanced<V> (V value, std::unique_ptr<BinaryTreeEnhanced<V>> left, std::unique_ptr<BinaryTreeEnhanced<V>> right) {
    //     _value = value;
    //     _left = std::move(left);
    //     _right = std::move(right);
    //     _left->setParent(*this);
    //     _right->setParent(*this);
    // }

    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t)
    {
        return t->_left_value;
    }
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        // WRITE YOUR CODE HERE
        return t->_parent;
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::unique_ptr<BinaryTreeEnhanced<V>> l,
                          std::unique_ptr<BinaryTreeEnhanced<V>> r)
{
    // WRITE YOUR CODE HERE
    std::unique_ptr<BinaryTreeEnhanced<V>> parent_ptr = std::unique_ptr<BinaryTreeEnhanced<V>>{
        new BinaryTreeEnhanced<V>{value, std::move(l), std::move(r)}};
    if (left(parent_ptr.get()))
        left(parent_ptr.get())->setParent(parent_ptr.get());
    if (right(parent_ptr.get()))
        right(parent_ptr.get())->setParent(parent_ptr.get());

    return parent_ptr;
}

#endif // __binary_tree_enhanced__