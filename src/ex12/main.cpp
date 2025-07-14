#include "../../include/Matrix.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST INVERSE DE MATRICE ===" << std::endl;
    
    // Test 1: Matrice 2x2 simple avec solution connue
    std::cout << "\n1. Matrice 2x2:" << std::endl;
    Matrix<float> m2(2, 2);
    m2(0, 0) = 2; m2(0, 1) = 1;
    m2(1, 0) = 1; m2(1, 1) = 1;
    
    std::cout << "Matrice originale A:" << std::endl;
    m2.print();
    std::cout << "Déterminant: " << m2.determinant() << std::endl;
    
    try {
        Matrix<float> inv2 = m2.inverse();
        std::cout << "\nInverse A⁻¹:" << std::endl;
        inv2.print();
        
        // Vérification: A × A⁻¹ = I
        std::cout << "\nVérification A × A⁻¹:" << std::endl;
        Matrix<float> result2(2, 2);
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 2; ++j) {
                result2(i, j) = 0;
                for (size_t k = 0; k < 2; ++k) {
                    result2(i, j) += m2(i, k) * inv2(k, j);
                }
            }
        }
        result2.print();
        std::cout << "Attendu: matrice identité" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test 2: Matrice 3x3
    std::cout << "\n2. Matrice 3x3:" << std::endl;
    Matrix<float> m3(3, 3);
    m3(0, 0) = 2; m3(0, 1) = 1; m3(0, 2) = 0;
    m3(1, 0) = 1; m3(1, 1) = 1; m3(1, 2) = 1;
    m3(2, 0) = 0; m3(2, 1) = 1; m3(2, 2) = 1;
    
    std::cout << "Matrice originale A:" << std::endl;
    m3.print();
    std::cout << "Déterminant: " << m3.determinant() << std::endl;
    
    try {
        Matrix<float> inv3 = m3.inverse();
        std::cout << "\nInverse A⁻¹:" << std::endl;
        inv3.print();
        
        // Vérification: A × A⁻¹ = I
        std::cout << "\nVérification A × A⁻¹:" << std::endl;
        Matrix<float> result3(3, 3);
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                result3(i, j) = 0;
                for (size_t k = 0; k < 3; ++k) {
                    result3(i, j) += m3(i, k) * inv3(k, j);
                }
            }
        }
        result3.print();
        std::cout << "Attendu: matrice identité" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test 3: Matrice identité (cas trivial)
    std::cout << "\n3. Matrice identité 2x2:" << std::endl;
    Matrix<float> id(2, 2, 0);
    id(0, 0) = 1; id(1, 1) = 1;
    
    std::cout << "Matrice:" << std::endl;
    id.print();
    
    try {
        Matrix<float> inv_id = id.inverse();
        std::cout << "Inverse:" << std::endl;
        inv_id.print();
        std::cout << "Attendu: matrice identité" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test 4: Matrice non-inversible (déterminant = 0)
    std::cout << "\n4. Matrice non-inversible:" << std::endl;
    Matrix<float> sing(2, 2);
    sing(0, 0) = 1; sing(0, 1) = 2;
    sing(1, 0) = 2; sing(1, 1) = 4;  // Ligne 2 = 2 × Ligne 1
    
    std::cout << "Matrice:" << std::endl;
    sing.print();
    std::cout << "Déterminant: " << sing.determinant() << std::endl;
    
    try {
        Matrix<float> inv_sing = sing.inverse();
        std::cout << "Erreur: cette matrice ne devrait pas être inversible!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    return 0;
}