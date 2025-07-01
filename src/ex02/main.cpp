/**
 * -----------------------------------------------------------------------
 * Ex 02 - Linear Interpolation
 * -----------------------------------------------------------------------
 * - Goal: Blend between two points: lerp(u, v, t) = u + t(v - u)
 * - Function: lerp(u, v, t) -> same_type_as_u_v
 * - Complexity: O(n) time, O(n) space
 * -----------------------------------------------------------------------
 */

#include "../../include/Vector.hpp"
#include "../../include/Matrix.hpp"
#include "../../include/Utils.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

template<typename T>
void print_vector(const Vector<T>& v, const std::string& name) {
    std::cout << CYAN << name << RESET << " = [";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
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
            std::cout << m(i, j);
            if (j < m.getCols() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void test_scalar_lerp() {
    std::cout << YELLOW << "\n=== Test 1: Interpolation scalaires ===" << RESET << std::endl;
    
    float u = 10.0f;
    float v = 20.0f;
    
    std::cout << "u = " << u << ", v = " << v << std::endl;
    
    // Test t = 0
    float result0 = lerp(u, v, 0.0f);
    std::cout << "lerp(u, v, 0.0) = " << result0 << GREEN << " (attendu: 10)" << RESET << std::endl;
    
    // Test t = 1
    float result1 = lerp(u, v, 1.0f);
    std::cout << "lerp(u, v, 1.0) = " << result1 << GREEN << " (attendu: 20)" << RESET << std::endl;
    
    // Test t = 0.5
    float result_half = lerp(u, v, 0.5f);
    std::cout << "lerp(u, v, 0.5) = " << result_half << GREEN << " (attendu: 15)" << RESET << std::endl;
    
    // Test t = 0.3
    float result_03 = lerp(u, v, 0.3f);
    std::cout << "lerp(u, v, 0.3) = " << result_03 << GREEN << " (attendu: 13)" << RESET << std::endl;
}

void test_vector_lerp() {
    std::cout << YELLOW << "\n=== Test 2: Interpolation vecteurs ===" << RESET << std::endl;
    
    Vector<float> u{1.0f, 2.0f, 3.0f};
    Vector<float> v{5.0f, 6.0f, 7.0f};
    
    print_vector(u, "u");
    print_vector(v, "v");
    
    // Test t = 0
    Vector<float> result0 = lerp(u, v, 0.0f);
    print_vector(result0, "lerp(u, v, 0.0)");
    std::cout << GREEN << "Attendu: [1, 2, 3]" << RESET << std::endl;
    
    // Test t = 1
    Vector<float> result1 = lerp(u, v, 1.0f);
    print_vector(result1, "lerp(u, v, 1.0)");
    std::cout << GREEN << "Attendu: [5, 6, 7]" << RESET << std::endl;
    
    // Test t = 0.5
    Vector<float> result_half = lerp(u, v, 0.5f);
    print_vector(result_half, "lerp(u, v, 0.5)");
    std::cout << GREEN << "Attendu: [3, 4, 5]" << RESET << std::endl;
    
    // Test t = 0.25
    Vector<float> result_quarter = lerp(u, v, 0.25f);
    print_vector(result_quarter, "lerp(u, v, 0.25)");
    std::cout << GREEN << "Attendu: [2, 3, 4]" << RESET << std::endl;
}

void test_matrix_lerp() {
    std::cout << YELLOW << "\n=== Test 3: Interpolation matrices ===" << RESET << std::endl;
    
    Matrix<float> u(2, 2, 1.0f);  // Matrice 2x2 remplie de 1
    Matrix<float> v(2, 2, 5.0f);  // Matrice 2x2 remplie de 5
    
    print_matrix(u, "u");
    print_matrix(v, "v");
    
    // Test t = 0.5
    Matrix<float> result_half = lerp(u, v, 0.5f);
    print_matrix(result_half, "lerp(u, v, 0.5)");
    std::cout << GREEN << "Attendu: matrice 2x2 remplie de 3" << RESET << std::endl;
}

void test_extrapolation() {
    std::cout << YELLOW << "\n=== Test 4: Extrapolation (t > 1 ou t < 0) ===" << RESET << std::endl;
    
    Vector<float> u{0.0f, 0.0f};
    Vector<float> v{10.0f, 20.0f};
    
    print_vector(u, "u");
    print_vector(v, "v");
    
    // Test t = 1.5 (extrapolation)
    Vector<float> result_15 = lerp(u, v, 1.5f);
    print_vector(result_15, "lerp(u, v, 1.5)");
    std::cout << GREEN << "Attendu: [15, 30] (au-delà de v)" << RESET << std::endl;
    
    // Test t = -0.5 (extrapolation inverse)
    Vector<float> result_neg = lerp(u, v, -0.5f);
    print_vector(result_neg, "lerp(u, v, -0.5)");
    std::cout << GREEN << "Attendu: [-5, -10] (en arrière de u)" << RESET << std::endl;
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 5: Cas d'erreur ===" << RESET << std::endl;
    
    try {
        // Test vecteurs de tailles différentes
        Vector<float> u{1.0f, 2.0f};
        Vector<float> v{3.0f, 4.0f, 5.0f};  // Taille différente !
        Vector<float> result = lerp(u, v, 0.5f);
        std::cout << RED << "ERREUR: Exception attendue pour tailles différentes!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée pour tailles différentes: " << e.what() << RESET << std::endl;
    }
    
    try {
        // Test vecteurs vides
        Vector<float> empty_u;
        Vector<float> empty_v;
        Vector<float> result = lerp(empty_u, empty_v, 0.5f);
        std::cout << RED << "ERREUR: Exception attendue pour vecteurs vides!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée pour vecteurs vides: " << e.what() << RESET << std::endl;
    }
}

void test_real_world_example() {
    std::cout << YELLOW << "\n=== Test 6: Exemple concret - Animation ===" << RESET << std::endl;
    
    // Position de départ et d'arrivée d'un objet en 3D
    Vector<float> pos_start{0.0f, 0.0f, 0.0f};    // Position initiale
    Vector<float> pos_end{100.0f, 50.0f, 25.0f};  // Position finale
    
    print_vector(pos_start, "Position départ");
    print_vector(pos_end, "Position arrivée");
    
    std::cout << "\nAnimation (progression de 0% à 100%):" << std::endl;
    
    for (float t = 0.0f; t <= 1.0f; t += 0.2f) {
        Vector<float> current_pos = lerp(pos_start, pos_end, t);
        std::cout << "t = " << t << " (";
        std::cout << (int)(t * 100) << "%) -> ";
        print_vector(current_pos, "");
    }
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "           TESTS INTERPOLATION LINÉAIRE" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_scalar_lerp();
    test_vector_lerp();
    test_matrix_lerp();
    test_extrapolation();
    test_error_cases();
    test_real_world_example();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINÉS" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}