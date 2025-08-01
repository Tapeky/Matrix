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

// ex02
// lerp(u, v, t) = u + t(v - u)

// Vector version
template<typename T>
Vector<T> lerp(const Vector<T>& u, const Vector<T>& v, T t) {
    if (u.size() != v.size()) throw std::invalid_argument("Undefined");
    if (u.size() == 0 || v.size() == 0) throw std::invalid_argument("Undefined");

    if (t == 0) return u;
    if (t == 1) return v;
    
    Vector<T> diff = v;
    diff.sub(u);
    diff.scl(t);

    Vector<T> result = u;
    result.add(diff);

    return result;
}

// Matrix version
template<typename T>
Matrix<T> lerp(const Matrix<T>& u, const Matrix<T>& v, T t) {
    if (u.getRows() != v.getRows() || u.getCols() != v.getCols()) 
        throw std::invalid_argument("Undefined");

    if (t == 0) return u;
    if (t == 1) return v;
    
    Matrix<T> diff = v;
    diff.sub(u);
    diff.scl(t);

    Matrix<T> result = u;
    result.add(diff);

    return result;
}

// Scalar version
template<typename T>
T lerp(const T& u, const T& v, T t) {
    return u + t * (v - u);
}


template<typename T>
Vector<T> mul_vec(const Matrix<T>& mat, const Vector<T>& vec) {
    if (mat.getCols() != vec.size()) throw std::invalid_argument("Tailles incompatibles");

    Vector<T> res(mat.getRows());
    for (size_t i = 0; i < mat.getRows(); i++) {
        T temp = 0;
        for (size_t j = 0; j < vec.size(); j++)
            temp += vec[j] * mat(i,j);
        res[i] = temp;
    }

    return res;
}

template<typename T>
Matrix<T> mul_mat(const Matrix<T>& mat1, const Matrix<T>& mat2) {
    if (mat1.getCols() != mat2.getRows()) throw std::invalid_argument("Tailles incompatibles");

    Matrix<T> res(mat1.getRows(), mat2.getCols());
    for (size_t col = 0; col < mat2.getCols(); col++) {
        Vector<T> column(mat2.getRows());
        for (size_t i = 0; i < mat2.getRows(); i++)
            column[i] = mat2(i, col);
        
        Vector<T> res_col = mul_vec(mat1, column);
        for (size_t i = 0; i < res_col.size(); i++)
            res(i,col) = res_col[i];
    }

    return res;
}