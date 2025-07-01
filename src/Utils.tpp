#include "Utils.hpp"

// Convert Vector to Matrix
template<typename T>
Matrix<T> reshape(const Vector<T>& vec, size_t rows, size_t cols) {
    if (vec.size() != rows * cols)
        throw std::invalid_argument("Taille incompatible");
    
    Matrix<T> result(rows, cols);
    
    for (size_t i = 0; i < vec.size(); i++) {
        size_t row = i / cols; 
        size_t col = i % cols;
        result(row, col) = vec[i];
    }

    return result;
}

// Convert Matrix to Vector
template<typename T>
Vector<T> reshape(const Matrix<T>& mat) {
    Vector<T> result(mat.getRows() * mat.getCols());
    
    size_t idx = 0;
    for (size_t i = 0; i < mat.getRows(); i++)
        for (size_t j = 0; j < mat.getCols(); j++)
            result[idx++] = mat(i, j);

    return result;
}

// ex01

template<typename T>
Vector<T> linear_combination(const std::vector<Vector<T>>& vec, const std::vector<T>& coeff) {
    if (vec.size() != coeff.size()) throw std::invalid_argument ("Undefined");
    if (vec.empty() || coeff.empty()) throw std::invalid_argument("Undefined");

    Vector<T> result(vec[0].size());
    for (size_t i = 0; i < coeff.size(); i++)
        for (size_t j = 0; j < vec[i].size(); j++)
            result[j] += vec[i][j] * coeff[i];

    return result;
}