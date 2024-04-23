#include <iostream>
#include <vector>

using std::vector;

int sum(vector<int> arr);

int main() {
    vector<int> test_case {1, 2, 3, 4};

    std::cout << sum(test_case) << "\n";

    return 0;
}

int sum(vector<int> arr) {
    if (arr.empty()) {
        return 0;
    }

    int x = arr[0];
    vector<int> rest = vector<int>(arr.begin() + 1, arr.end());

    return x + sum(rest);

}