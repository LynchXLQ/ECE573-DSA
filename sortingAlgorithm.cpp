//
// Created by Linqi Xiao on 4/22/2023.
//

#include "sortingAlgorithm.h"

template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

vector<int> SortingAlgorithm::bubbleSort(vector<int> vec) {
    int len = vec.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (vec[i] > vec[j]) {
                mySwap(vec[i], vec[j]);
            }
        }
    }
    return vec;
}


vector<int> SortingAlgorithm::insertionSort(vector<int> vec) {
    int len = vec.size();
    for (int i = 0; i < len - 1; i++) {
        int j = i;
        int tmp = vec[i + 1];
        while (j >= 0 && tmp < vec[j]) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = tmp;
    }
    return vec;
}

vector<int> SortingAlgorithm::selectionSort(vector<int> vec) {
    int len = vec.size();
    int minIndex;
    for (int i = 0; i < len - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        mySwap(vec[minIndex], vec[i]);
    }
    return vec;
}

void merge(std::vector<int>& myVector, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid+1, k = 0;
    while (i <= mid && j <= right) {
        if (myVector[i] <= myVector[j]) {
            temp[k] = myVector[i];
            ++i;
        }
        else {
            temp[k] = myVector[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid) {
        temp[k] = myVector[i];
        ++i;
        ++k;
    }
    while (j <= right) {
        temp[k] = myVector[j];
        ++j;
        ++k;
    }
    for (int a = 0; a < k; ++a) {
        myVector[left + a] = temp[a];
    }
}

vector<int> SortingAlgorithm::mergeSort(vector<int> vec) {
    int n = vec.size();
    int curr_size;
    int left_start;
    for (curr_size = 1; curr_size < n; curr_size *= 2) {
        for (left_start = 0; left_start < n-1; left_start += 2*curr_size) {
            int mid = std::min(left_start + curr_size - 1, n-1);
            int right = std::min(left_start + 2*curr_size - 1, n-1);
            merge(vec, left_start, mid, right);
        }
    }
    return vec;
}

vector<int> SortingAlgorithm::countingSort(vector<int> vec) {
    int len = vec.size();
    int Min = vec[0], Max = vec[0];
    for (int i = 1; i < len; i++)
    {
        Max = max(Max, vec[i]);
        Min = min(Min, vec[i]);
    }
    int bias = 0 - Min;
    vector<int> bucket(Max - Min + 1, 0);
    for (int i = 0; i < len; i++)
    {
        bucket[vec[i] + bias]++;
    }
    int index = 0, i = 0;
    while (index < len)
    {
        if (bucket[i])
        {
            vec[index] = i - bias;
            bucket[i]--;
            index++;
        }
        else
            i++;
    }
    return vec;
}