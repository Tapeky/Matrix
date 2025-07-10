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
};

#include "../src/Matrix.tpp"

#endif