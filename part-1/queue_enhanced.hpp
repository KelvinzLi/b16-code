#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>
#include <iostream>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;
    using Queue<T>::Queue::_position;
    using Queue<T>::Queue::_storage;
    using Queue<T>::Queue::_size;
    using Queue<T>::Queue::_head;

    // Access the element at the back of the queue
    T &back()
    {
        // WRITE YOUR CODE HERE
        return _storage[_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        // WRITE YOUR CODE HERE
        return _storage[_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        // WRITE YOUR CODE HERE
        assert(_size < _storage.size());
        int head_idx = _head();
        int next_idx = head_idx + 1;
        if (next_idx == _storage.size()) {
            next_idx = 0;
        }
        _storage[next_idx] = value;
        _size++;
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // WRITE YOUR CODE HERE
        assert(_size >= 1);
        _position = _tail();
        _size--;
    }

    // Remove all elements from the queue
    void clear() { 
        // WRITE YOUR CODE HERE
        _size = 1;
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // WRITE YOUR CODE HERE
        if (_position == _storage.size() - 1) {
            return 0;
        } else {
            return _position + 1;
        }
    }
};

#endif // __queue_enhanced__