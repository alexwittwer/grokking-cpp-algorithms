#include <iostream>
#include <vector>

using std::vector, std::cout, std::cin;

int count(vector<int> arr);

int main() {
    vector<int> myArray {1, 2, 3, 4, 5};

    cout << count(myArray) << "\n";

    return 0;
}

int count(vector<int> arr) {
    if (arr.empty()) {
        return 0;
    }
    vector<int> copiedArr = vector<int>(arr.begin() + 1, arr.end());


    return (1 + count(copiedArr));
}