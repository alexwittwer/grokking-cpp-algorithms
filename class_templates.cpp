#include <iostream>
#include <memory>

template <typename T>
struct DynamicArray{
    int size;
    std::unique_ptr<T[]> ptr;

    DynamicArray(int new_size) : size(new_size), ptr(new T[new_size]) {}

    void fill(T value){
        for (int i = 0; i < size; i++){
            ptr[i] = value;
        }
    }

    void print() {
        for (int i = 0; i < size; i++){
            std::cout << ptr[i] << " ";
        }

        std::cout << "\n";
    }
};

int main() {
    DynamicArray<int> int_array(10);
    int_array.fill(4);
    int_array.print();

    DynamicArray<double> dbl_array(10);
    dbl_array.fill(3.14);
    dbl_array.print();

    return 0;
}