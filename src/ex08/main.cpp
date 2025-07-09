/**
 * -----------------------------------------------------------------------
 * Ex 08 - Trace
 * -----------------------------------------------------------------------
 * - Goal: Sum of diagonal elements: tr(A) = Σ Aᵢᵢ
 * - Method: Matrix.trace() -> scalar
 * - Complexity: O(n) time
 * - Only for square matrices
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
    std::cout << CYAN << name << RESET << " = " << std::endl;
    for (size_t i = 0; i < m.getRows(); ++i) {
        std::cout << "  [";
        for (size_t j = 0; j < m.getCols(); ++j) {
            std::cout << std::fixed << std::setprecision(2) << m(i, j);
            if (j < m.getCols() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void test_basic_trace() {
    std::cout << YELLOW << "\n=== Test 1: Trace de base ===" << RESET << std::endl;
    
    Matrix<float> A(3, 3);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
    A(1, 0) = 4.0f; A(1, 1) = 5.0f; A(1, 2) = 6.0f;
    A(2, 0) = 7.0f; A(2, 1) = 8.0f; A(2, 2) = 9.0f;
    
    print_matrix(A, "A");
    
    float trace = A.trace();
    std::cout << "tr(A) = " << CYAN << trace << RESET << std::endl;
    
    // Calcul manuel: 1 + 5 + 9 = 15
    std::cout << GREEN << "Attendu: 15.00 (1 + 5 + 9)" << RESET << std::endl;
}

void test_identity_matrix() {
    std::cout << YELLOW << "\n=== Test 2: Matrice identité ===" << RESET << std::endl;
    
    Matrix<float> I(4, 4);
    // Remplir avec des 0
    for (size_t i = 0; i < I.getRows(); ++i) {
        for (size_t j = 0; j < I.getCols(); ++j) {
            I(i, j) = (i == j) ? 1.0f : 0.0f;
        }
    }
    
    print_matrix(I, "I (identité 4×4)");
    
    float trace = I.trace();
    std::cout << "tr(I) = " << CYAN << trace << RESET << std::endl;
    
    std::cout << GREEN << "Attendu: 4.00 (dimension de la matrice)" << RESET << std::endl;
}

void test_diagonal_matrix() {
    std::cout << YELLOW << "\n=== Test 3: Matrice diagonale ===" << RESET << std::endl;
    
    Matrix<float> D(3, 3);
    D(0, 0) = 2.0f; D(0, 1) = 0.0f; D(0, 2) = 0.0f;
    D(1, 0) = 0.0f; D(1, 1) = 3.0f; D(1, 2) = 0.0f;
    D(2, 0) = 0.0f; D(2, 1) = 0.0f; D(2, 2) = 5.0f;
    
    print_matrix(D, "D (diagonale)");
    
    float trace = D.trace();
    std::cout << "tr(D) = " << CYAN << trace << RESET << std::endl;
    
    std::cout << GREEN << "Attendu: 10.00 (2 + 3 + 5)" << RESET << std::endl;
}

void test_zero_matrix() {
    std::cout << YELLOW << "\n=== Test 4: Matrice zéro ===" << RESET << std::endl;
    
    Matrix<float> Z(2, 2, 0.0f);  // Matrice remplie de zéros
    
    print_matrix(Z, "Z (matrice zéro)");
    
    float trace = Z.trace();
    std::cout << "tr(Z) = " << CYAN << trace << RESET << std::endl;
    
    std::cout << GREEN << "Attendu: 0.00" << RESET << std::endl;
}

void test_negative_values() {
    std::cout << YELLOW << "\n=== Test 5: Valeurs négatives ===" << RESET << std::endl;
    
    Matrix<float> A(3, 3);
    A(0, 0) = -1.0f; A(0, 1) = 2.0f; A(0, 2) = -3.0f;
    A(1, 0) = 4.0f; A(1, 1) = -5.0f; A(1, 2) = 6.0f;
    A(2, 0) = -7.0f; A(2, 1) = 8.0f; A(2, 2) = -9.0f;
    
    print_matrix(A, "A (avec négatifs)");
    
    float trace = A.trace();
    std::cout << "tr(A) = " << CYAN << trace << RESET << std::endl;
    
    // Calcul manuel: -1 + (-5) + (-9) = -15
    std::cout << GREEN << "Attendu: -15.00 (-1 + (-5) + (-9))" << RESET << std::endl;
}

void test_single_element() {
    std::cout << YELLOW << "\n=== Test 6: Matrice 1×1 ===" << RESET << std::endl;
    
    Matrix<float> A(1, 1);
    A(0, 0) = 42.0f;
    
    print_matrix(A, "A (1×1)");
    
    float trace = A.trace();
    std::cout << "tr(A) = " << CYAN << trace << RESET << std::endl;
    
    std::cout << GREEN << "Attendu: 42.00" << RESET << std::endl;
}

void test_different_types() {
    std::cout << YELLOW << "\n=== Test 7: Types différents ===" << RESET << std::endl;
    
    // Test avec int
    Matrix<int> A_int(2, 2);
    A_int(0, 0) = 10; A_int(0, 1) = 20;
    A_int(1, 0) = 30; A_int(1, 1) = 40;
    
    print_matrix(A_int, "A (int)");
    
    int trace_int = A_int.trace();
    std::cout << "tr(A) = " << CYAN << trace_int << RESET << std::endl;
    
    // Test avec double
    Matrix<double> A_double(2, 2);
    A_double(0, 0) = 1.5; A_double(0, 1) = 2.5;
    A_double(1, 0) = 3.5; A_double(1, 1) = 4.5;
    
    print_matrix(A_double, "A (double)");
    
    double trace_double = A_double.trace();
    std::cout << "tr(A) = " << CYAN << trace_double << RESET << std::endl;
    
    std::cout << GREEN << "Attendu: 50 (int), 6.00 (double)" << RESET << std::endl;
}

void test_trace_properties() {
    std::cout << YELLOW << "\n=== Test 8: Propriétés de la trace ===" << RESET << std::endl;
    
    Matrix<float> A(2, 2);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f;
    A(1, 0) = 3.0f; A(1, 1) = 4.0f;
    
    Matrix<float> B(2, 2);
    B(0, 0) = 5.0f; B(0, 1) = 6.0f;
    B(1, 0) = 7.0f; B(1, 1) = 8.0f;
    
    print_matrix(A, "A");
    print_matrix(B, "B");
    
    float tr_A = A.trace();
    float tr_B = B.trace();
    
    // Test: tr(A + B) = tr(A) + tr(B)
    Matrix<float> A_plus_B = A;
    A_plus_B.add(B);
    float tr_A_plus_B = A_plus_B.trace();
    
    std::cout << "tr(A) = " << CYAN << tr_A << RESET << std::endl;
    std::cout << "tr(B) = " << CYAN << tr_B << RESET << std::endl;
    std::cout << "tr(A + B) = " << CYAN << tr_A_plus_B << RESET << std::endl;
    std::cout << "tr(A) + tr(B) = " << CYAN << (tr_A + tr_B) << RESET << std::endl;
    
    if (std::abs(tr_A_plus_B - (tr_A + tr_B)) < 1e-6f) {
        std::cout << GREEN << "✓ Propriété linéaire vérifiée: tr(A + B) = tr(A) + tr(B)" << RESET << std::endl;
    } else {
        std::cout << RED << "✗ Erreur dans la propriété linéaire!" << RESET << std::endl;
    }
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 9: Cas d'erreur ===" << RESET << std::endl;
    
    // Test matrice non carrée
    try {
        Matrix<float> A(2, 3);  // 2×3 non carrée
        A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
        A(1, 0) = 4.0f; A(1, 1) = 5.0f; A(1, 2) = 6.0f;
        
        print_matrix(A, "A (2×3 non carrée)");
        
        float trace = A.trace();
        std::cout << RED << "ERREUR: Exception attendue pour matrice non carrée!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée: " << e.what() << RESET << std::endl;
    }
    
    // Test matrice vide
    try {
        Matrix<float> empty(0, 0);
        float trace = empty.trace();
        std::cout << RED << "ERREUR: Exception attendue pour matrice vide!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée pour matrice vide: " << e.what() << RESET << std::endl;
    }
}

void test_real_world_example() {
    std::cout << YELLOW << "\n=== Test 10: Exemple concret - Matrice de covariance ===" << RESET << std::endl;
    
    // Matrice de covariance typique (symétrique, définie positive)
    Matrix<float> cov(3, 3);
    cov(0, 0) = 1.0f; cov(0, 1) = 0.5f; cov(0, 2) = 0.2f;
    cov(1, 0) = 0.5f; cov(1, 1) = 2.0f; cov(1, 2) = 0.3f;
    cov(2, 0) = 0.2f; cov(2, 1) = 0.3f; cov(2, 2) = 1.5f;
    
    print_matrix(cov, "Matrice de covariance");
    
    float trace = cov.trace();
    std::cout << "tr(Cov) = " << CYAN << trace << RESET << std::endl;
    
    std::cout << BLUE << "-> La trace représente la variance totale" << RESET << std::endl;
    std::cout << BLUE << "-> En statistiques: tr(Cov) = Σ var(Xᵢ)" << RESET << std::endl;
    std::cout << GREEN << "Attendu: 4.50 (1.0 + 2.0 + 1.5)" << RESET << std::endl;
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "                 TESTS TRACE" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_basic_trace();
    test_identity_matrix();
    test_diagonal_matrix();
    test_zero_matrix();
    test_negative_values();
    test_single_element();
    test_different_types();
    test_trace_properties();
    test_error_cases();
    test_real_world_example();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINÉS" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}