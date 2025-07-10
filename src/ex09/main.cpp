/**
 * -----------------------------------------------------------------------
 * Ex 09 - Transpose
 * -----------------------------------------------------------------------
 * - Goal: Flip matrix over diagonal: Bᵢⱼ = Aⱼᵢ
 * - Method: Matrix.transpose() -> Matrix
 * - Complexity: O(nm) time, O(nm) space
 * - Works for any matrix dimensions (not just square)
 * -----------------------------------------------------------------------
 */

#include "../../include/Matrix.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

template<typename T>
void print_matrix(const Matrix<T>& m, const std::string& name) {
    std::cout << CYAN << name << RESET << " (" << m.getRows() << "×" << m.getCols() << ") = " << std::endl;
    for (size_t i = 0; i < m.getRows(); ++i) {
        std::cout << "  [";
        for (size_t j = 0; j < m.getCols(); ++j) {
            std::cout << std::fixed << std::setprecision(2) << m(i, j);
            if (j < m.getCols() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void test_basic_transpose() {
    std::cout << YELLOW << "\n=== Test 1: Transposée de base ===" << RESET << std::endl;
    
    Matrix<float> A(2, 3);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
    A(1, 0) = 4.0f; A(1, 1) = 5.0f; A(1, 2) = 6.0f;
    
    print_matrix(A, "A");
    
    Matrix<float> At = A.transpose();
    print_matrix(At, "Aᵀ");
    
    std::cout << GREEN << "Vérification: A(0,1) = " << A(0, 1) << " → Aᵀ(1,0) = " << At(1, 0) << RESET << std::endl;
}

void test_square_matrix() {
    std::cout << YELLOW << "\n=== Test 2: Matrice carrée ===" << RESET << std::endl;
    
    Matrix<float> A(3, 3);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
    A(1, 0) = 4.0f; A(1, 1) = 5.0f; A(1, 2) = 6.0f;
    A(2, 0) = 7.0f; A(2, 1) = 8.0f; A(2, 2) = 9.0f;
    
    print_matrix(A, "A");
    
    Matrix<float> At = A.transpose();
    print_matrix(At, "Aᵀ");
    
    std::cout << GREEN << "Diagonal conservée: A(0,0) = " << A(0, 0) << " = Aᵀ(0,0) = " << At(0, 0) << RESET << std::endl;
}

void test_tall_matrix() {
    std::cout << YELLOW << "\n=== Test 3: Matrice haute (3×2) ===" << RESET << std::endl;
    
    Matrix<float> A(3, 2);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f;
    A(1, 0) = 3.0f; A(1, 1) = 4.0f;
    A(2, 0) = 5.0f; A(2, 1) = 6.0f;
    
    print_matrix(A, "A");
    
    Matrix<float> At = A.transpose();
    print_matrix(At, "Aᵀ");
    
    std::cout << GREEN << "Transformation: 3×2 → 2×3" << RESET << std::endl;
}

void test_row_vector() {
    std::cout << YELLOW << "\n=== Test 4: Vecteur ligne (1×4) ===" << RESET << std::endl;
    
    Matrix<float> A(1, 4);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f; A(0, 3) = 4.0f;
    
    print_matrix(A, "A (vecteur ligne)");
    
    Matrix<float> At = A.transpose();
    print_matrix(At, "Aᵀ (vecteur colonne)");
    
    std::cout << GREEN << "Transformation: 1×4 → 4×1" << RESET << std::endl;
}

void test_column_vector() {
    std::cout << YELLOW << "\n=== Test 5: Vecteur colonne (4×1) ===" << RESET << std::endl;
    
    Matrix<float> A(4, 1);
    A(0, 0) = 1.0f;
    A(1, 0) = 2.0f;
    A(2, 0) = 3.0f;
    A(3, 0) = 4.0f;
    
    print_matrix(A, "A (vecteur colonne)");
    
    Matrix<float> At = A.transpose();
    print_matrix(At, "Aᵀ (vecteur ligne)");
    
    std::cout << GREEN << "Transformation: 4×1 → 1×4" << RESET << std::endl;
}

void test_identity_matrix() {
    std::cout << YELLOW << "\n=== Test 6: Matrice identité ===" << RESET << std::endl;
    
    Matrix<float> I(3, 3);
    for (size_t i = 0; i < I.getRows(); ++i) {
        for (size_t j = 0; j < I.getCols(); ++j) {
            I(i, j) = (i == j) ? 1.0f : 0.0f;
        }
    }
    
    print_matrix(I, "I");
    
    Matrix<float> It = I.transpose();
    print_matrix(It, "Iᵀ");
    
    std::cout << GREEN << "Propriété: Iᵀ = I (matrice identité)" << RESET << std::endl;
}

void test_symmetric_matrix() {
    std::cout << YELLOW << "\n=== Test 7: Matrice symétrique ===" << RESET << std::endl;
    
    Matrix<float> A(3, 3);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
    A(1, 0) = 2.0f; A(1, 1) = 4.0f; A(1, 2) = 5.0f;
    A(2, 0) = 3.0f; A(2, 1) = 5.0f; A(2, 2) = 6.0f;
    
    print_matrix(A, "A (symétrique)");
    
    Matrix<float> At = A.transpose();
    print_matrix(At, "Aᵀ");
    
    // Vérifier si A = Aᵀ
    bool is_symmetric = true;
    for (size_t i = 0; i < A.getRows() && is_symmetric; ++i) {
        for (size_t j = 0; j < A.getCols() && is_symmetric; ++j) {
            if (std::abs(A(i, j) - At(i, j)) > 1e-6f) {
                is_symmetric = false;
            }
        }
    }
    
    if (is_symmetric) {
        std::cout << GREEN << "✓ Propriété vérifiée: A = Aᵀ (matrice symétrique)" << RESET << std::endl;
    } else {
        std::cout << RED << "✗ Erreur: A ≠ Aᵀ" << RESET << std::endl;
    }
}

void test_double_transpose() {
    std::cout << YELLOW << "\n=== Test 8: Double transposée ===" << RESET << std::endl;
    
    Matrix<float> A(2, 3);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
    A(1, 0) = 4.0f; A(1, 1) = 5.0f; A(1, 2) = 6.0f;
    
    print_matrix(A, "A");
    
    Matrix<float> At = A.transpose();
    Matrix<float> Att = At.transpose();
    
    print_matrix(Att, "(Aᵀ)ᵀ");
    
    // Vérifier si (Aᵀ)ᵀ = A
    bool is_equal = true;
    for (size_t i = 0; i < A.getRows() && is_equal; ++i) {
        for (size_t j = 0; j < A.getCols() && is_equal; ++j) {
            if (std::abs(A(i, j) - Att(i, j)) > 1e-6f) {
                is_equal = false;
            }
        }
    }
    
    if (is_equal) {
        std::cout << GREEN << "✓ Propriété vérifiée: (Aᵀ)ᵀ = A" << RESET << std::endl;
    } else {
        std::cout << RED << "✗ Erreur: (Aᵀ)ᵀ ≠ A" << RESET << std::endl;
    }
}

void test_different_types() {
    std::cout << YELLOW << "\n=== Test 9: Types différents ===" << RESET << std::endl;
    
    // Test avec int
    Matrix<int> A_int(2, 3);
    A_int(0, 0) = 1; A_int(0, 1) = 2; A_int(0, 2) = 3;
    A_int(1, 0) = 4; A_int(1, 1) = 5; A_int(1, 2) = 6;
    
    print_matrix(A_int, "A (int)");
    
    Matrix<int> At_int = A_int.transpose();
    print_matrix(At_int, "Aᵀ (int)");
    
    // Test avec double
    Matrix<double> A_double(2, 2);
    A_double(0, 0) = 1.5; A_double(0, 1) = 2.5;
    A_double(1, 0) = 3.5; A_double(1, 1) = 4.5;
    
    print_matrix(A_double, "A (double)");
    
    Matrix<double> At_double = A_double.transpose();
    print_matrix(At_double, "Aᵀ (double)");
    
    std::cout << GREEN << "✓ Fonctionne avec différents types numériques" << RESET << std::endl;
}

void test_single_element() {
    std::cout << YELLOW << "\n=== Test 10: Matrice 1×1 ===" << RESET << std::endl;
    
    Matrix<float> A(1, 1);
    A(0, 0) = 42.0f;
    
    print_matrix(A, "A (1×1)");
    
    Matrix<float> At = A.transpose();
    print_matrix(At, "Aᵀ (1×1)");
    
    std::cout << GREEN << "Propriété: Pour 1×1, Aᵀ = A" << RESET << std::endl;
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "              TESTS TRANSPOSE" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_basic_transpose();
    test_square_matrix();
    test_tall_matrix();
    test_row_vector();
    test_column_vector();
    test_identity_matrix();
    test_symmetric_matrix();
    test_double_transpose();
    test_different_types();
    test_single_element();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINÉS" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}