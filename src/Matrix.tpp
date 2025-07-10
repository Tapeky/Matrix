#include "Matrix.hpp"

template<typename T>
Matrix<T>::Matrix() : data_(), rows_(0), cols_(0) {}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : data_(rows * cols), rows_(rows), cols_(cols) {}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T value) : data_(rows * cols, value), rows_(rows), cols_(cols) {}

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

// Ex00 operations
template<typename T>
void Matrix<T>::add(const Matrix<T>& other) {
	if (rows_ != other.rows_ || cols_ != other.cols_) throw std::invalid_argument("Dimensions incompatibles.");
	if (data_.size() == 0) throw std::invalid_argument("Les matrices sont vides.");
	
	for (size_t i = 0; i < data_.size(); i++)
		data_[i] += other.data_[i];
}

template<typename T>
void Matrix<T>::sub(const Matrix<T>& other) {
	if (rows_ != other.rows_ || cols_ != other.cols_) throw std::invalid_argument("Dimensions incompatibles.");
	if (data_.size() == 0) throw std::invalid_argument("Les matrices sont vides.");

	for (size_t i = 0; i < data_.size(); i++)
		data_[i] -= other.data_[i];
}

template<typename T>
void Matrix<T>::scl(T scalar) {
	for (size_t i = 0; i < data_.size(); i++)
		data_[i] *= scalar;
}



// Ex08
template<typename T>
T Matrix<T>::trace() const {
	if (!isSquare()) throw std::invalid_argument ("La matrice n'est pas carre");

	T res = 0;
	for (size_t i = 0; i < rows_; i++)
		res += (*this)(i, i);

	return res;
}


// Ex09
template<typename T>
Matrix<T> Matrix<T>::transpose() const{
	Matrix<T> res(cols_, rows_);

	for (size_t i = 0; i < rows_; i++)
		for (size_t j = 0; j < cols_; j++)
			res(j, i) = (*this)(i, j);

	return res;
}
