//
// Created by Linqi Xiao on 4/22/2023.
//

#ifndef SORTED_SORTINGALGORITHM_H
#define SORTED_SORTINGALGORITHM_H

#include <iostream>
#include <vector>

using namespace std;

class SortingAlgorithm {
public:
    vector<int> bubbleSort(vector<int> vec);
    vector<int> insertionSort(vector<int> vec);
    vector<int> selectionSort(vector<int> vec);
    vector<int> mergeSort(vector<int> vec);
    vector<int> countingSort(vector<int> vec);
};


#endif //SORTED_SORTINGALGORITHM_H
