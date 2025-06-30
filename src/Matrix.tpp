#include "Matrix.hpp"

template<typename T>
Matrix<T>::Matrix() : rows_(0), cols_(0) {}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) , data_(rows * cols) {}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T value) : rows_(rows), cols_(cols) , data_(rows * cols, value) {}

template<typename T> // Write
T& Matrix<T>::operator()(size_t i, size_t j) {
	return data_[i * cols_ + j];
}

template<typename T> // Read
const T& Matrix<T>::operator()(size_t i, size_t j) const {
	return data_[i * cols_ + j];
}

template<typename T>
void Matrix<T>::print() const {
	for (size_t i = 0; i < rows_; i++) {
		std::cout << '[';
		for (size_t j = 0; j < cols_; j++) {
			std::cout << (*this)(i, j);
			if (j != cols_ - 1) std::cout << ", ";
		}
		std::cout << ']' << std::endl;
	}
}