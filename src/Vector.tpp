#include "Vector.hpp"
#include "Utils.hpp"
#include <limits>

// Add vector to this vector (ex00)
template<typename T>
void Vector<T>::add(const Vector<T>& other) {
    if (size() != other.size()) throw std::invalid_argument("Les vecteurs n'ont pas la meme taille.");
    if (size() == 0) throw std::invalid_argument("Les vecteurs sont vides.");
    
    for (size_t i = 0; i < data.size(); i++)
        data[i] += other.data[i];
}

// Subtract vector from this vector  (ex00)
template<typename T>
void Vector<T>::sub(const Vector<T>& other) {
    if (size() != other.size()) throw std::invalid_argument("Les vecteurs n'ont pas la meme taille.");
    if (size() == 0) throw std::invalid_argument("Les vecteurs sont vides.");

    for (size_t i = 0; i < data.size(); i++)
        data[i] -= other.data[i];
}

// Scale this vector by scalar (ex00)
template<typename T>
void Vector<T>::scl(T scalar) {
    for (size_t i = 0; i < data.size(); i++)
        data[i] *= scalar;
}


// Produit scalaire / Dot product (ex03)
template<typename T>
T Vector<T>::dot(const Vector<T>& other) const {
    if (size() != other.size()) throw std::invalid_argument("Les vecteurs n'ont pas la meme taille.");
    if (size() == 0) throw std::invalid_argument("Les vecteurs sont vides.");
    
    T res = 0;
    for (size_t i = 0; i < size(); i++)
        res += (*this)[i] * other[i];

    return res;
}

// Norm (ex04)

// Manatthan
template<typename T>
T Vector<T>::norm1() const {
    if (size() == 0) throw std::invalid_argument("Le vecteur est vide.");

    T res = 0;
    for (size_t i = 0; i < size(); i++)
        res += my_abs((*this)[i]);

    return res;
}

// Euclide
template<typename T>
T Vector<T>::norm() const {
    if (size() == 0) throw std::invalid_argument("Le vecteur est vide.");

    T res = 0;
    for (size_t i = 0; i < size(); i++)
         res += my_square((*this)[i]);

    res = my_sqrt(res);
    return res;
}

// Infinite
template<typename T>
T Vector<T>::norm_inf() const {
    if (size() == 0) throw std::invalid_argument("Le vecteur est vide.");

    T max = std::numeric_limits<T>::lowest();
    
    for (size_t i = 0; i < size(); i++)
        if (my_abs((*this)[i]) > max) max = my_abs((*this)[i]);

    return max;
}

// Ex05 Cosine
template<typename T>
T Vector<T>::angle_cos(const Vector<T>& other) const {
    if (size() != other.size()) throw std::invalid_argument("Les vecteurs n'ont pas la meme taille.");
    if (size() == 0) throw std::invalid_argument("Les vecteurs sont vides.");

    T norm_u = this->norm();
    T norm_v = other.norm();

    if (norm_u == 0|| norm_v == 0) throw std::invalid_argument("Division par zero");

    T dot_product = this->dot(other);
    
    return dot_product / (norm_u * norm_v);
}

// Ex06 (cross product)  u×v = [u₂v₃ - u₃v₂, u₃v₁ - u₁v₃, u₁v₂ - u₂v₁]
template<typename T>
Vector<T> Vector<T>::cross_product(const Vector<T>& other) const {
    if (size() != 3) throw std::invalid_argument("Vecteur de mauvaise taille");
    if (size() != other.size()) throw std::invalid_argument("Vecteur de mauvaise taille");

    Vector<T> res(3);
    res[0] = this->operator[](1) * other[2] - this->operator[](2) * other[1];
    res[1] = this->operator[](2) * other[0] - this->operator[](0) * other[2];
    res[2] = this->operator[](0) * other[1] - this->operator[](1) * other[0];

    return res;
}