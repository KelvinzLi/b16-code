#ifndef __radix_sort__
#define __radix_sort__

#include <algorithm>
#include <limits>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template <typename I>
static constexpr int num_digits_v =
    std::numeric_limits<typename I::value_type>::digits;

vector<vector<vector<int>::iterator>> split_on_digit(vector<vector<int>::iterator> iters, int digit_idx){
    vector<vector<vector<int>::iterator>> split {{}, {}};

    int mask =  1 << digit_idx;

    for (int ii = 0; ii < iters.size(); ii++){
        int thebit = (*(iters[ii]) & mask) >> digit_idx;
        split[thebit].push_back(iters[ii]);
    }

    for (int jj = 0; jj < split.size(); jj++){
        if (split[jj].size() == 0){
            split.erase(split.begin() + jj);
        }
    }

    return split;
}

template <typename I>
void radix_sort(const I &begin, const I &end,
                int digit = num_digits_v<I>)
{
    vector<vector<vector<int>::iterator>> splits{ {} };
    for (I iter = begin; iter < end; iter++){
        splits[0].push_back(iter);
    }

    for (int digit_idx = digit; digit_idx >= 0; digit_idx--){
        int current_split_num = splits.size();
        for (int split_idx = 0; split_idx < current_split_num; split_idx++){
            vector<vector<vector<int>::iterator>> new_split = split_on_digit(splits[split_idx], digit_idx);
            splits.insert(splits.end(), new_split.begin(), new_split.end());
        }
        splits.erase(splits.begin(), splits.begin() + current_split_num);
        
        // Printing current step splits
        for (int jj = 0; jj < splits.size(); jj++) {
            for (int ii = 0; ii < splits[jj].size(); ii++){
                cout << *(splits[jj][ii]) << " ";
            }
            cout << "| ";
        }
        cout << endl;
    }

    vector<int> sorted {};
    for (int split_idx = 0; split_idx < splits.size(); split_idx++){
        for (int ii = 0; ii < splits[split_idx].size(); ii++){
            sorted.push_back(*(splits[split_idx][ii]));
        }
    }

    int counter = 0;
    for (I iter = begin; iter < end; iter++){
        *iter = sorted[counter];
        counter++;
    }
}

#endif // __radix_sort__