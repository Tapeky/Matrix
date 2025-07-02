#ifndef UTILS_HPP
#define UTILS_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>

template<typename T>
T my_abs(T x) { return (x >= 0) ? x : -x; }

template<typename T>
T my_square(const T& obj) { return obj * obj ;}

template<typename T>
T my_sqrt(const T& obj) {
	if (obj <= 0.0f) return 0.0f;
    if (obj == 1.0f) return 1.0f;

	T x = obj / 2;
	const T precision = static_cast<T>(1e-10);
        
	for (int i = 0; i < 20; ++i) {
		T x_new = (x + obj / x) / 2;
            
		if (my_abs(x_new - x) < precision)
			return x_new;
		
		x = x_new;
	}
        
	return x;
}

// Vector to Matrix reshape
template<typename T>
Matrix<T> reshape(const Vector<T>& vec, size_t rows, size_t cols);

// Matrix to Vector reshape  
template<typename T>
Vector<T> reshape(const Matrix<T>& mat);

// ex01
template<typename T>
Vector<T> linear_combination(const std::vector<Vector<T>>& vec, const std::vector<T>& coeff);

// ex02
template<typename T>
Vector<T> lerp(const Vector<T>& u, const Vector<T>& v, T t);

template<typename T>
Matrix<T> lerp(const Matrix<T>& u, const Matrix<T>& v, T t);

template<typename T>
T lerp(const T& u, const T& v, T t);

#include "../src/Utils.tpp"

#endif