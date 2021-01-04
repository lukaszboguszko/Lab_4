#include <iostream>
#include <string>
#include <fstream>

class Matrix 
{
 
public:

    double** ma; //macierz elementow typu double
    int n; //liczba wierszy
    int m; //liczba kolumn

    Matrix(int n, int m);
    Matrix(int n);

    void set(int n, int m, double val);
    double get(int n, int m);
    Matrix add(Matrix &m2);
    Matrix subtract(Matrix &m2);
    Matrix multiply(Matrix &m2);
    int cols();
    int rows();
    void print();
    void store(std::string filename, std::string path);

    Matrix(std::string path);
    ~Matrix();
};

