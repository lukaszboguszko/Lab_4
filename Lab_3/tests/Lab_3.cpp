#include <iostream>
#include "Matrix.h"
#include <string>

int main()
{
    int n = 4;
    int m = 5;

    Matrix matrix1 = Matrix(n, m);
    Matrix matrix2 = Matrix(n);
    Matrix matrix3 = Matrix("matrix.txt");
    Matrix matrix4 = Matrix(n, m);
    Matrix matrix5 = Matrix("multiply.txt");
    Matrix matrix6 = Matrix(5, 5);

    matrix1.print();
    std::cout << std::endl;
    matrix2.set(1, 1, 3.0);
    matrix2.print();
    std::cout << std::endl;
    matrix3.print();
    std::cout << std::endl;
    matrix1.store("matrix_stored.txt", "matrix_stored.txt");
    std::cout << "Liczba kolumn macierzy matrix1: " << matrix1.cols() << std::endl;
    std::cout << "Liczba wierszy macierzy matrix1: " << matrix1.rows() << std::endl;
    std::cout << "matrix3[2][3] = " << matrix3.get(2, 3) << std::endl;
    std::cout << std::endl;
    matrix4 = matrix1.add(matrix3);
    matrix4.print();
    std::cout << std::endl;
    matrix1.subtract(matrix3);
    matrix1.print();
    std::cout << std::endl;
    matrix6 = matrix3.multiply(matrix5);
    matrix6.print();
    std::cout << std::endl;
    return 0;
}
