#include <iostream>

#include "matrix.hpp"

int main(int argc, char const *argv[])
{
    double v1[] = {1, 3, 4, 8, 2, 7};
    Matrix m1 = Matrix(2, 3, v1);

    double v2[] = {1, 3, 4, 8, 2, 7};
    Matrix m2 = Matrix(3, 2, v2);

    std::cout << "Hello, Data Science from scratch!" << std::endl;

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m1 * m2 << std::endl;
    std::cout << 2 * m1 << std::endl;
    std::cout << 3.14 * m2 << std::endl;
    std::cout << 3.14 * m1 * m2 << std::endl;
    return 0;
}
