#include "Matrix.h"

Matrix::Matrix(int n, int m)
{
	this->n = n;
	this->m = m;
	this->ma = new double* [n];
	for (int i = 0; i < n; ++i) {
		this->ma[i] = new double[m];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			this->ma[i][j] = 0.0;
		}
	}
}

Matrix::Matrix(int n)
{
	this->n = this->m = n;
	this->ma = new double* [n];
	for (int i = 0; i < n; ++i) {
		this->ma[i] = new double[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
			this->ma[i][j] = 0.0;
		}
	}
}

void Matrix::set(int n, int m, double val)
{
	this->ma[n][m] = val;
}

double Matrix::get(int n, int m)
{
	return this->ma[n][m];
}

Matrix Matrix::add(Matrix &m2)
{
	Matrix m3 = Matrix(this->n, this->m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m3.ma[i][j] = this->ma[i][j] + m2.ma[i][j];
		}
	}
	return m3;
}

Matrix Matrix::subtract(Matrix &m2)
{
	Matrix m3 = Matrix(this->n, this->m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m3.ma[i][j] = this->ma[i][j] - m2.ma[i][j];
		}
	}
	return m3;
}

Matrix Matrix::multiply(Matrix &m2)
{
	Matrix m3 = Matrix(this->n, m2.m);

	for (int i = 0; i < this->n; ++i){
		for (int j = 0; j < m2.m; ++j){
			for (int k = 0; k < this->m; ++k){
				m3.ma[i][j] += this->ma[i][k] * m2.ma[k][j];
			}
		}	
	}
	return m3;
}

int Matrix::cols()
{
	return this->m;
}

int Matrix::rows()
{
	return this->n;
}

void Matrix::print()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << " " << this->ma[i][j];
		}
		std::cout << std::endl;
	}
}

void Matrix::store(std::string filename, std::string path)
{
	std::fstream file;
	file.open(path, std::ios::out);

	file << n << " " << m << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			file << this->ma[i][j] << " ";
		}
		file << "\n";
	}
	file.close();
}

Matrix::Matrix(std::string path)
{
	std::ifstream file(path);
	file >> this->n >> this->m;

	this->ma = new double* [n];
	for (int i = 0; i < n; ++i) {
		this->ma[i] = new double[m];
	}

	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			file >> this->ma[i][j];
		}
	}
	file.close();
}

Matrix::~Matrix()
{
}
