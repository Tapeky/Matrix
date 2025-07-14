#include "../../include/Matrix.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST RANG DE MATRICE ===" << std::endl;
    
    // Test 1: Matrice identité 3x3 (rang = 3)
    std::cout << "\n1. Matrice identité 3x3:" << std::endl;
    Matrix<float> id(3, 3, 0);
    id(0, 0) = 1; id(1, 1) = 1; id(2, 2) = 1;
    
    std::cout << "Matrice:" << std::endl;
    id.print();
    std::cout << "Rang: " << id.rank() << std::endl;
    std::cout << "Attendu: 3" << std::endl;
    
    // Test 2: Matrice avec rang déficient (rang = 2)
    std::cout << "\n2. Matrice 3x3 avec rang 2:" << std::endl;
    Matrix<float> m1(3, 3);
    m1(0, 0) = 1; m1(0, 1) = 2; m1(0, 2) = 3;
    m1(1, 0) = 4; m1(1, 1) = 5; m1(1, 2) = 6;
    m1(2, 0) = 5; m1(2, 1) = 7; m1(2, 2) = 9;  // L3 = L1 + L2
    
    std::cout << "Matrice:" << std::endl;
    m1.print();
    std::cout << "Rang: " << m1.rank() << std::endl;
    std::cout << "Attendu: 2" << std::endl;
    
    // Test 3: Matrice rectangulaire 2x3 (rang = 2)
    std::cout << "\n3. Matrice rectangulaire 2x3:" << std::endl;
    Matrix<float> m2(2, 3);
    m2(0, 0) = 1; m2(0, 1) = 2; m2(0, 2) = 3;
    m2(1, 0) = 4; m2(1, 1) = 5; m2(1, 2) = 6;
    
    std::cout << "Matrice:" << std::endl;
    m2.print();
    std::cout << "Rang: " << m2.rank() << std::endl;
    std::cout << "Attendu: 2" << std::endl;
    
    // Test 4: Matrice nulle (rang = 0)
    std::cout << "\n4. Matrice nulle 2x2:" << std::endl;
    Matrix<float> zero(2, 2, 0);
    
    std::cout << "Matrice:" << std::endl;
    zero.print();
    std::cout << "Rang: " << zero.rank() << std::endl;
    std::cout << "Attendu: 0" << std::endl;
    
    // Test 5: Matrice 2x2 inversible (rang = 2)
    std::cout << "\n5. Matrice 2x2 inversible:" << std::endl;
    Matrix<float> m3(2, 2);
    m3(0, 0) = 2; m3(0, 1) = 1;
    m3(1, 0) = 1; m3(1, 1) = 1;
    
    std::cout << "Matrice:" << std::endl;
    m3.print();
    std::cout << "Rang: " << m3.rank() << std::endl;
    std::cout << "Déterminant: " << m3.determinant() << std::endl;
    std::cout << "Attendu: rang = 2 (car det ≠ 0)" << std::endl;
    
    return 0;
}