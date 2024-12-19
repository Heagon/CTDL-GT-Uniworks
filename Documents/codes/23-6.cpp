#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Hàm tìm giá trị lớn nhất
template <typename T>
T max_value(const std::vector<T>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Hàm tìm giá trị nhỏ nhất
template <typename T>
T min_value(const std::vector<T>& arr) {
    return *std::min_element(arr.begin(), arr.end());
}

// Hàm tìm giá trị tuyệt đối lớn nhất
template <typename T>
T max_abs_value(const std::vector<T>& arr) {
    return *std::max_element(arr.begin(), arr.end(), [](T a, T b) {
        return std::abs(a) < std::abs(b);
    });
}

// Hàm tìm giá trị tuyệt đối nhỏ nhất
template <typename T>
T min_abs_value(const std::vector<T>& arr) {
    return *std::min_element(arr.begin(), arr.end(), [](T a, T b) {
        return std::abs(a) < std::abs(b);
    });
}
// het bai 1

template <typename T>
class Array {
private:
    T* data;
    int size;
public:
    Array(int size) : size(size) {
        data = new T[size];
    }

    Array(const std::vector<T>& vec) {
        size = vec.size();
        data = new T[size];
        std::copy(vec.begin(), vec.end(), data);
    }

    ~Array() {
        delete[] data;
    }

    Array(const Array& other) {
        size = other.size;
        data = new T[size];
        std::copy(other.data, other.data + size, data);
    }

    Array& operator=(const Array& other) {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        data = new T[size];
        std::copy(other.data, other.data + size, data);
        return *this;
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    Array operator+(const Array& other) const {
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Array operator-(const Array& other) const {
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    Array& operator+=(const Array& other) {
        for (int i = 0; i < size; ++i) {
            data[i] += other.data[i];
        }
        return *this;
    }

    Array& operator-=(const Array& other) {
        for (int i = 0; i < size; ++i) {
            data[i] -= other.data[i];
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        for (int i = 0; i < arr.size; ++i) {
            os << arr.data[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Array& arr) {
        for (int i = 0; i < arr.size; ++i) {
            is >> arr.data[i];
        }
        return is;
    }

    int getSize() const {
        return size;
    }

    const T* getData() const {
        return data;
    }
};
//het bai 2

// Hàm thực hiện phép toán
template <typename T, typename OP>
void operation(const T* p1, const T* p2, T* result, int n, OP op) {
    for (int i = 0; i < n; ++i) {
        result[i] = op(p1[i], p2[i]);
    }
}

// Định nghĩa các phép toán theo dạng đối tượng hàm (functor)
template <typename T>
struct Add {
    T operator()(const T& a, const T& b) const {
        return a + b;
    }
};

template <typename T>
struct Subtract {
    T operator()(const T& a, const T& b) const {
        return a - b;
    }
};

template <typename T>
struct Multiply {
    T operator()(const T& a, const T& b) const {
        return a * b;
    }
};

template <typename T>
struct Divide {
    T operator()(const T& a, const T& b) const {
        return a / b;
    }
};

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {5, 4, 3, 2, 1};

    Array<int> arr1(vec1);
    Array<int> arr2(vec2);
    Array<int> result(arr1.getSize());

    // Sử dụng hàm thực hiện phép toán
    operation<int, Add<int>>(arr1.getData(), arr2.getData(), result.getData(), vec1.size(), Add<int>());
    std::cout << "Result of addition: " << result << std::endl;

    operation<int, Subtract<int>>(arr1.getData(), arr2.getData(), result.getData(), vec1.size(), Subtract<int>());
    std::cout << "Result of subtraction: " << result << std::endl;

    operation<int, Multiply<int>>(arr1.getData(), arr2.getData(), result.getData(), vec1.size(), Multiply<int>());
    std::cout << "Result of multiplication: " << result << std::endl;

    operation<int, Divide<int>>(arr1.getData(), arr2.getData(), result.getData(), vec1.size(), Divide<int>());
    std::cout << "Result of division: " << result << std::endl;

    return 0;
}
