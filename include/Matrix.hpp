#ifndef MATRIX_HPP
#define MATRIX_HPP

# include <vector>
# include <iostream>

template<typename T>
class Matrix {
	private:
		std::vector<T> data_;
		size_t rows_;
		size_t cols_;
	
	public:
		Matrix();
		Matrix(size_t rows, size_t cols);
		Matrix(size_t rows, size_t cols, T value);

		T& operator()(size_t i, size_t j);
		const T& operator()(size_t i, size_t j) const;

		size_t	getRows() const { return rows_ ;}
		size_t	getCols() const { return cols_ ;}
		bool	isSquare() const { return cols_ == rows_ ;}
		void	print() const;

		// Ex00 operations
		void add(const Matrix<T>& other);
		void sub(const Matrix<T>& other);
		void scl(T scalar);

		// Ex08
		T trace() const;

		// Ex09
		Matrix<T> transpose() const;

		// Ex10
		void swap_rows(size_t i, size_t j);
		void scale_row(size_t i, T scalar);
		void add_row_multiple(size_t i, size_t j, T scalar);  // Ligne i += scalar * Ligne j
		Matrix<T> row_echelon() const;

		// Ex11
		Matrix<T> row_echelon(int& swap_count) const;
		T determinant() const;

		// Ex12
		Matrix<T> inverse() const;

		// Ex13
		size_t rank() const;
};

#include "../src/Matrix.tpp"

#endif