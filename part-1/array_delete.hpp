#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    // WRITE YOUR CODE HERE
    typename std::vector<T>::iterator iter = A.begin();
    for (int ii = 0; ii < A.size() - index; ii++) {
        *(iter + ii) = *(iter + ii + 1);
    }
    A.resize(A.size() - 1);
}

#endif // __array_delete__