// Description: This program demonstrates the binary search algorithm.
// Author: Alex Wittwer
// Date: 4/22/2024
// Path: binary_search.cpp
#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{

    std::vector<int> arr = { 1,
                             2,
                             3,
                             4,
                             5,
                             6,
    };

    int target = 1;
    int result = binarySearch(arr, target);

    if (result != -1)
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}

