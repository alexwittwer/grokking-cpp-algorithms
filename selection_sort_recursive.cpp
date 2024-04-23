#include <iostream>
#include <vector>

using std::vector;

template <typename T>
T findSmallest(vector<T>& arr);
template <typename T>
vector<T> selectionSort(vector<T>& arr);

int main()
{
    vector<int> arr = {1, 5, 4, 8, 2, 3, 9, 10};
    vector<int> &ref = arr;

    vector<int> sortedArray = selectionSort(ref);

    for (int num : sortedArray) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    return 0;
}

template <typename T>
vector<T> selectionSort(vector<T>& arr) {
    vector<T> newArr {};
    for (int i = arr.size() - 1; i >=0 ; i--) {
        T smallestValue = findSmallest(arr);
        newArr.push_back(smallestValue);
    }

    return newArr;
}

template <typename T>
T findSmallest(vector<T>& arr) {
    if (arr.empty()) {
        throw std::domain_error("Array is empty");
    }

    T smallest = arr[0]; // initialize it as first value
    int smallestIndex {0};

    for (int i = 1; i < arr.size(); i++){
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallestIndex = i;
        }
    }
    arr.erase(arr.begin() + smallestIndex);

    return smallest;
}