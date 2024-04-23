#include <iostream>
#include <vector>

using std::vector, std::cout;

int max(vector<int> arr);

int main() {
    vector<int> myArr {1, 2, 3, 4, 22, 5, 6, 7, 8};

    cout << max(myArr) << "\n";

    return 0;
}

int max(vector<int> arr) {

    if (arr.size() == 1) {
        return arr[0];
    }

    vector<int> left = vector<int>(arr.begin(), arr.begin() + arr.size() / 2);
    vector<int> right = vector<int>(arr.begin() + arr.size()/2, arr.end());

    return (max(left) > max(right) ? max(left) : max(right));
}