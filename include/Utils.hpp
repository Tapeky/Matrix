#ifndef UTILS_HPP
#define UTILS_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>

// Vector to Matrix reshape
template<typename T>
Matrix<T> reshape(const Vector<T>& vec, size_t rows, size_t cols);

// Matrix to Vector reshape  
template<typename T>
Vector<T> reshape(const Matrix<T>& mat);

// ex01
template<typename T>
Vector<T> linear_combination(const std::vector<Vector<T>>& vec, const std::vector<T>& coeff);

#include "../src/Utils.tpp"

#endif