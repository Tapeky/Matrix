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


// Ex10
template<typename T>
void Matrix<T>::swap_rows(size_t i, size_t j) {
	for (size_t k = 0; k < cols_; k++) {
		std::swap((*this)(i, k), (*this)(j, k));
	}
}

template<typename T>
void Matrix<T>::scale_row(size_t i, T scalar) {
	for (size_t k = 0; k < cols_; k++)
		(*this)(i,k) *= scalar;
}

template<typename T>
void Matrix<T>::add_row_multiple(size_t i, size_t j, T scalar) {
	for (size_t k = 0; k < cols_; k++)
		(*this)(i,k) += scalar * (*this)(j, k);
}

template<typename T>
Matrix<T> Matrix<T>::row_echelon() const {
	Matrix<T> cpy = *this;
	size_t pivot_row = 0;
	
	for (size_t col = 0; col < cols_; col++) {
		size_t pivot_found = pivot_row;
		for (size_t row = pivot_row; row < rows_; row++) {
			if (cpy(row, col) != 0) {
				pivot_found = row;
				break;
			}
		}

		if (pivot_found < rows_ && cpy(pivot_found, col) != 0) {
			if (pivot_found != pivot_row)
				cpy.swap_rows(pivot_row, pivot_found);

			for (size_t row = pivot_row + 1; row < rows_; row++) {
				if (cpy(row, col) != 0) {
					T factor = -cpy(row, col) / cpy(pivot_row, col);
					cpy.add_row_multiple(row, pivot_row, factor);
				}
			}
			pivot_row++;
		}
	}

	return cpy;
}


// Ex11
template<typename T>
Matrix<T> Matrix<T>::row_echelon(int& swap_count) const {
	Matrix<T> cpy = *this;
	size_t pivot_row = 0;
	swap_count = 0;
	
	for (size_t col = 0; col < cols_; col++) {
		size_t pivot_found = pivot_row;
		for (size_t row = pivot_row; row < rows_; row++) {
			if (cpy(row, col) != 0) {
				pivot_found = row;
				break;
			}
		}

		if (pivot_found < rows_ && cpy(pivot_found, col) != 0) {
			if (pivot_found != pivot_row) {
				cpy.swap_rows(pivot_row, pivot_found);
				swap_count++;
			}

			for (size_t row = pivot_row + 1; row < rows_; row++) {
				if (cpy(row, col) != 0) {
					T factor = -cpy(row, col) / cpy(pivot_row, col);
					cpy.add_row_multiple(row, pivot_row, factor);
				}
			}
			pivot_row++;
		}
	}

	return cpy;
}

template<typename T> 
T Matrix<T>::determinant() const {
	if (!isSquare()) throw std::invalid_argument("Le determinant n existe que pour les matrices carrees");	
	
	int swap_count = 0;
	Matrix<T> cpy = this->row_echelon(swap_count);

	T determinant = 1;
	for (size_t i = 0; i < rows_; i++)
		determinant *= cpy(i, i);

	if (swap_count % 2 == 1)
		determinant *= -1;

	return determinant;
}

template<typename T>
Matrix<T> Matrix<T>::inverse() const {
	if (!isSquare()) throw std::invalid_argument("La matrice n'est pas carre");
	if (this->determinant() == 0) throw std::invalid_argument("Si le derterminant d'une matrice est egale a 0 alors elle n est pas reversible");

	// Cree une matrice augmente [A|I]
	Matrix<T> augmented(rows_, cols_ * 2);
	for (size_t row = 0; row < rows_; row++) {
		for (size_t col = 0; col < cols_ * 2; col++) {
			if (col < cols_)
				augmented(row, col) = (*this)(row, col);
			else
				augmented(row, col) = (col - cols_ == row) ? 1 : 0;
		}
	}

	// forward_elimination
	size_t n = rows_;
	for (size_t col = 0; col < n; ++col) {
		// trouve le pivot
		size_t pivot_row = col;
		for (size_t row = pivot_row; row < rows_; ++row) {
			if (augmented(row, col) != 0) {
				pivot_row = row;
				break;
			}
		}
		if (augmented(pivot_row, col) == 0)
			throw std::runtime_error("La matrix n est pas reversible");

		if (pivot_row != col)
      		augmented.swap_rows(pivot_row, col);
		
		// Normaliser le pivot
		T pivot_value = augmented(col, col);
		augmented.scale_row(col, T(1) / pivot_value);

		// Eliminer sous le pivot
		for (size_t row = col + 1; row < n; ++row) {
			if (augmented(row, col) != 0) {
				T factor = -augmented(row, col);
				augmented.add_row_multiple(row, col, factor);
			}
  		}
	}
	
	// back_substitution
	for (int col = n - 1; col >= 0; --col) {
		for (int row = 0; row < col; ++row) {
			if (augmented(row, col) != 0) {
				T factor = -augmented(row, col);
				augmented.add_row_multiple(row, col, factor);
			}
		}
  	}

	// Extraire A⁻¹ de la partie droite
	Matrix<T> result(rows_, cols_);
	for (size_t row = 0; row < rows_; ++row)
		for (size_t col = 0; col < cols_; ++col)
			result(row, col) = augmented(row, col + cols_);

	return result;
}