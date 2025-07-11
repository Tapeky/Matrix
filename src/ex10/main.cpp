#include "../../include/Matrix.hpp"
#include <iostream>

int main() {
    // Test simple 2x2
    Matrix<float> m(2, 2);
    m(0, 0) = 2; m(0, 1) = 4;
    m(1, 0) = 1; m(1, 1) = 3;
    
    std::cout << "Matrice originale:" << std::endl;
    m.print();
    
    Matrix<float> echelon = m.row_echelon();
    std::cout << "\nForme échelonnée:" << std::endl;
    echelon.print();
    
    return 0;
}