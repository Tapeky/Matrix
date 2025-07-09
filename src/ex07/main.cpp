/**
 * -----------------------------------------------------------------------
 * Ex 07 - Matrix Multiplication
 * -----------------------------------------------------------------------
 * - Goal: Matrix-vector (Av) and matrix-matrix (AB) multiplication
 * - Functions: mul_vec(A, v) -> Vector, mul_mat(A, B) -> Matrix
 * - Rules: (m×n) × (n×1) → (m×1), (m×n) × (n×p) → (m×p)
 * -----------------------------------------------------------------------
 */

#include "../../include/Matrix.hpp"
#include "../../include/Vector.hpp"
#include "../../include/Utils.hpp"
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
void print_vector(const Vector<T>& v, const std::string& name) {
    std::cout << CYAN << name << RESET << " = [";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << std::fixed << std::setprecision(2) << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

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

void test_basic_mul_vec() {
    std::cout << YELLOW << "\n=== Test 1: Multiplication matrice-vecteur de base ===" << RESET << std::endl;
    
    Matrix<float> A(2, 3);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
    A(1, 0) = 4.0f; A(1, 1) = 5.0f; A(1, 2) = 6.0f;
    
    Vector<float> v{7.0f, 8.0f, 9.0f};
    
    print_matrix(A, "A (2×3)");
    print_vector(v, "v (3×1)");
    
    Vector<float> result = mul_vec(A, v);
    print_vector(result, "A × v");
    
    // Calcul manuel: [1*7+2*8+3*9, 4*7+5*8+6*9] = [7+16+27, 28+40+54] = [50, 122]
    std::cout << GREEN << "Attendu: [50.00, 122.00]" << RESET << std::endl;
}

void test_identity_matrix() {
    std::cout << YELLOW << "\n=== Test 2: Matrice identité ===" << RESET << std::endl;
    
    Matrix<float> I(3, 3);
    I(0, 0) = 1.0f; I(0, 1) = 0.0f; I(0, 2) = 0.0f;
    I(1, 0) = 0.0f; I(1, 1) = 1.0f; I(1, 2) = 0.0f;
    I(2, 0) = 0.0f; I(2, 1) = 0.0f; I(2, 2) = 1.0f;
    
    Vector<float> v{5.0f, 3.0f, 8.0f};
    
    print_matrix(I, "I (identité)");
    print_vector(v, "v");
    
    Vector<float> result = mul_vec(I, v);
    print_vector(result, "I × v");
    
    std::cout << GREEN << "Attendu: [5.00, 3.00, 8.00] (identité)" << RESET << std::endl;
}

void test_scaling_matrix() {
    std::cout << YELLOW << "\n=== Test 3: Matrice de mise à l'échelle ===" << RESET << std::endl;
    
    Matrix<float> S(2, 2);
    S(0, 0) = 2.0f; S(0, 1) = 0.0f;
    S(1, 0) = 0.0f; S(1, 1) = 3.0f;
    
    Vector<float> v{4.0f, 5.0f};
    
    print_matrix(S, "S (scaling)");
    print_vector(v, "v");
    
    Vector<float> result = mul_vec(S, v);
    print_vector(result, "S × v");
    
    std::cout << GREEN << "Attendu: [8.00, 15.00] (scaling x2, y3)" << RESET << std::endl;
}

void test_basic_mul_mat() {
    std::cout << YELLOW << "\n=== Test 4: Multiplication matrice-matrice de base ===" << RESET << std::endl;
    
    Matrix<float> A(2, 3);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f; A(0, 2) = 3.0f;
    A(1, 0) = 4.0f; A(1, 1) = 5.0f; A(1, 2) = 6.0f;
    
    Matrix<float> B(3, 2);
    B(0, 0) = 7.0f; B(0, 1) = 8.0f;
    B(1, 0) = 9.0f; B(1, 1) = 10.0f;
    B(2, 0) = 11.0f; B(2, 1) = 12.0f;
    
    print_matrix(A, "A (2×3)");
    print_matrix(B, "B (3×2)");
    
    Matrix<float> result = mul_mat(A, B);
    print_matrix(result, "A × B (2×2)");
    
    std::cout << GREEN << "Attendu:" << RESET << std::endl;
    std::cout << GREEN << "  [58.00, 64.00]" << RESET << std::endl;
    std::cout << GREEN << "  [139.00, 154.00]" << RESET << std::endl;
}

void test_square_matrices() {
    std::cout << YELLOW << "\n=== Test 5: Matrices carrées ===" << RESET << std::endl;
    
    Matrix<float> A(2, 2);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f;
    A(1, 0) = 3.0f; A(1, 1) = 4.0f;
    
    Matrix<float> B(2, 2);
    B(0, 0) = 5.0f; B(0, 1) = 6.0f;
    B(1, 0) = 7.0f; B(1, 1) = 8.0f;
    
    print_matrix(A, "A");
    print_matrix(B, "B");
    
    Matrix<float> AB = mul_mat(A, B);
    Matrix<float> BA = mul_mat(B, A);
    
    print_matrix(AB, "A × B");
    print_matrix(BA, "B × A");
    
    std::cout << BLUE << "Note: A×B != B×A (non-commutativité)" << RESET << std::endl;
}

void test_associativity() {
    std::cout << YELLOW << "\n=== Test 6: Associativité (A×B)×C = A×(B×C) ===" << RESET << std::endl;
    
    Matrix<float> A(2, 2);
    A(0, 0) = 1.0f; A(0, 1) = 2.0f;
    A(1, 0) = 3.0f; A(1, 1) = 4.0f;
    
    Matrix<float> B(2, 2);
    B(0, 0) = 5.0f; B(0, 1) = 6.0f;
    B(1, 0) = 7.0f; B(1, 1) = 8.0f;
    
    Matrix<float> C(2, 2);
    C(0, 0) = 1.0f; C(0, 1) = 0.0f;
    C(1, 0) = 0.0f; C(1, 1) = 2.0f;
    
    Matrix<float> AB = mul_mat(A, B);
    Matrix<float> BC = mul_mat(B, C);
    
    Matrix<float> AB_C = mul_mat(AB, C);
    Matrix<float> A_BC = mul_mat(A, BC);
    
    print_matrix(AB_C, "(A×B)×C");
    print_matrix(A_BC, "A×(B×C)");
    
    std::cout << GREEN << "Vérification: les deux résultats doivent être identiques" << RESET << std::endl;
}

void test_transformation_composition() {
    std::cout << YELLOW << "\n=== Test 7: Composition de transformations ===" << RESET << std::endl;
    
    // Scaling × 2
    Matrix<float> S(2, 2);
    S(0, 0) = 2.0f; S(0, 1) = 0.0f;
    S(1, 0) = 0.0f; S(1, 1) = 2.0f;
    
    // Translation (approximation pour 2D)
    Matrix<float> T(2, 2);
    T(0, 0) = 1.0f; T(0, 1) = 0.0f;
    T(1, 0) = 0.0f; T(1, 1) = 1.0f;
    
    Vector<float> point{3.0f, 4.0f};
    
    print_matrix(S, "S (scaling ×2)");
    print_vector(point, "point");
    
    // Appliquer scaling puis transformation
    Vector<float> scaled = mul_vec(S, point);
    print_vector(scaled, "après scaling");
    
    // Ou composer les transformations
    Matrix<float> composed = mul_mat(T, S);
    Vector<float> final = mul_vec(composed, point);
    
    print_matrix(composed, "T × S (composé)");
    print_vector(final, "transformation composée");
    
    std::cout << BLUE << "Utile en infographie pour chaîner les transformations!" << RESET << std::endl;
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 8: Cas d'erreur ===" << RESET << std::endl;
    
    try {
        Matrix<float> A(2, 3);
        Vector<float> v{1.0f, 2.0f};  // Taille incompatible
        mul_vec(A, v);
        std::cout << RED << "ERREUR: Exception attendue pour mul_vec!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception mul_vec: " << e.what() << RESET << std::endl;
    }
    
    try {
        Matrix<float> A(2, 3);
        Matrix<float> B(4, 2);  // Taille incompatible
        mul_mat(A, B);
        std::cout << RED << "ERREUR: Exception attendue pour mul_mat!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception mul_mat: " << e.what() << RESET << std::endl;
    }
}

void test_real_world_example() {
    std::cout << YELLOW << "\n=== Test 9: Exemple concret - Système d'équations ===" << RESET << std::endl;
    
    // Système: 2x + 3y = 13
    //          1x + 4y = 14
    Matrix<float> A(2, 2);
    A(0, 0) = 2.0f; A(0, 1) = 3.0f;
    A(1, 0) = 1.0f; A(1, 1) = 4.0f;
    
    Vector<float> b{13.0f, 14.0f};
    
    print_matrix(A, "A (coefficients)");
    print_vector(b, "b (résultats)");
    
    std::cout << BLUE << "-> Représente le système Ax = b" << RESET << std::endl;
    std::cout << BLUE << "-> Solution: x = 2, y = 3" << RESET << std::endl;
    
    // Vérification si on connaît la solution
    Vector<float> x{2.0f, 3.0f};
    Vector<float> verification = mul_vec(A, x);
    print_vector(verification, "A × [2, 3]");
    
    std::cout << GREEN << "-> Vérification: doit égaler b = [13, 14]" << RESET << std::endl;
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "           TESTS MULTIPLICATION MATRICIELLE" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_basic_mul_vec();
    test_identity_matrix();
    test_scaling_matrix();
    test_basic_mul_mat();
    test_square_matrices();
    test_associativity();
    test_transformation_composition();
    test_error_cases();
    test_real_world_example();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINÉS" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}