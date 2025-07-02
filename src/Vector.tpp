#include "Vector.hpp"

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