#include "../../include/Matrix.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST DETERMINANT AVEC ÉTAPES ===" << std::endl;
    
    // Test 1: Matrice 2x2 simple
    std::cout << "\n1. Matrice 2x2:" << std::endl;
    Matrix<float> m2(2, 2);
    m2(0, 0) = 1; m2(0, 1) = 3;
    m2(1, 0) = 2; m2(1, 1) = 4;
    
    std::cout << "Matrice originale:" << std::endl;
    m2.print();
    
    int swap_count = 0;
    Matrix<float> echelon2 = m2.row_echelon(swap_count);
    std::cout << "\nForme échelonnée:" << std::endl;
    echelon2.print();
    std::cout << "Nombre de swaps: " << swap_count << std::endl;
    std::cout << "Pivots: " << echelon2(0,0) << " × " << echelon2(1,1) << " = " << (echelon2(0,0) * echelon2(1,1)) << std::endl;
    std::cout << "Signe des swaps: " << (swap_count % 2 == 0 ? "+1" : "-1") << std::endl;
    std::cout << "Déterminant final: " << m2.determinant() << std::endl;
    std::cout << "Attendu: -2" << std::endl;
    
    // Test 2: Matrice 3x3 
    std::cout << "\n2. Matrice 3x3:" << std::endl;
    Matrix<float> m3(3, 3);
    m3(0, 0) = 2; m3(0, 1) = 1; m3(0, 2) = 3;
    m3(1, 0) = 1; m3(1, 1) = 0; m3(1, 2) = 1;
    m3(2, 0) = 1; m3(2, 1) = 2; m3(2, 2) = 1;
    
    std::cout << "Matrice originale:" << std::endl;
    m3.print();
    
    int swap_count3 = 0;
    Matrix<float> echelon3 = m3.row_echelon(swap_count3);
    std::cout << "\nForme échelonnée:" << std::endl;
    echelon3.print();
    std::cout << "Nombre de swaps: " << swap_count3 << std::endl;
    std::cout << "Pivots: " << echelon3(0,0) << " × " << echelon3(1,1) << " × " << echelon3(2,2) << " = " << (echelon3(0,0) * echelon3(1,1) * echelon3(2,2)) << std::endl;
    std::cout << "Signe des swaps: " << (swap_count3 % 2 == 0 ? "+1" : "-1") << std::endl;
    std::cout << "Déterminant final: " << m3.determinant() << std::endl;
    
    // Test 3: Matrice identité 3x3
    std::cout << "\n3. Matrice identité 3x3:" << std::endl;
    Matrix<float> id(3, 3, 0);
    id(0, 0) = 1; id(1, 1) = 1; id(2, 2) = 1;
    
    std::cout << "Matrice:" << std::endl;
    id.print();
    std::cout << "Déterminant: " << id.determinant() << std::endl;
    std::cout << "Attendu: 1" << std::endl;
    
    // Test 4: Matrice avec déterminant 0
    std::cout << "\n4. Matrice singulière (det = 0):" << std::endl;
    Matrix<float> sing(2, 2);
    sing(0, 0) = 1; sing(0, 1) = 2;
    sing(1, 0) = 2; sing(1, 1) = 4;  // Ligne 2 = 2 × Ligne 1
    
    std::cout << "Matrice:" << std::endl;
    sing.print();
    std::cout << "Déterminant: " << sing.determinant() << std::endl;
    std::cout << "Attendu: 0" << std::endl;
    
    return 0;
}