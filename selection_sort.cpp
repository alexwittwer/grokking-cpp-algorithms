#include <iostream>
#include <vector>

using std::vector;

template <typename T>
int findSmallest(const vector<T>& arr, int start);
template <typename T>
vector<T> selectionSort(vector<T> arr);

int main()
{
    vector<int> arr = {5, 3, 6, 2, 10, 1, 4, 9, 8, 7, 0, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    vector<int> sortedArr = selectionSort(arr);

    for (int num : sortedArr) 
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    return 0;
}

template <typename T>
int findSmallest(const vector<T>& arr, int start)
{
    T smallest = arr[start];
    int smallest_index = start;

    for (int i = start; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

template <typename T>
vector<T> selectionSort(vector<T> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int smallestIndex = findSmallest(arr, i);
        std::swap(arr[i], arr[smallestIndex]);
    }
    return arr;
}