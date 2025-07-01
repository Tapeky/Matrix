/**
 * -----------------------------------------------------------------------
 * Ex 01 - Linear Combination
 * -----------------------------------------------------------------------
 * Goal: Compute Σ(λᵢ * vᵢ) for vectors vᵢ and scalars λᵢ
 * Function: linear_combination(vectors, coefficients) -> Vector
 * Complexity: O(n) time, O(n) space
 * -----------------------------------------------------------------------
 */

#include "../../include/Vector.hpp"
#include "../../include/Utils.hpp"
#include <iostream>
#include <vector>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

template<typename T>
void print_vector(const Vector<T>& v, const std::string& name) {
    std::cout << CYAN << name << RESET << " = [";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void test_basic_combination() {
    std::cout << YELLOW << "\n=== Test 1: Combinaison basique ===" << RESET << std::endl;
    
    // Test: 2*[1,2] + 3*[4,1] = [2,4] + [12,3] = [14,7]
    Vector<float> v1{1.0f, 2.0f};
    Vector<float> v2{4.0f, 1.0f};
    std::vector<Vector<float>> vectors = {v1, v2};
    std::vector<float> coeffs = {2.0f, 3.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    std::cout << "Coefficients: [2, 3]" << std::endl;
    
    Vector<float> result = linear_combination(vectors, coeffs);
    print_vector(result, "Résultat");
    std::cout << GREEN << "Attendu: [14, 7]" << RESET << std::endl;
}

void test_three_vectors() {
    std::cout << YELLOW << "\n=== Test 2: Trois vecteurs ===" << RESET << std::endl;
    
    // Test: 1*[1,0] + 2*[0,1] + 3*[1,1] = [1,0] + [0,2] + [3,3] = [4,5]
    Vector<float> v1{1.0f, 0.0f};
    Vector<float> v2{0.0f, 1.0f};
    Vector<float> v3{1.0f, 1.0f};
    std::vector<Vector<float>> vectors = {v1, v2, v3};
    std::vector<float> coeffs = {1.0f, 2.0f, 3.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    print_vector(v3, "v3");
    std::cout << "Coefficients: [1, 2, 3]" << std::endl;
    
    Vector<float> result = linear_combination(vectors, coeffs);
    print_vector(result, "Résultat");
    std::cout << GREEN << "Attendu: [4, 5]" << RESET << std::endl;
}

void test_negative_coeffs() {
    std::cout << YELLOW << "\n=== Test 3: Coefficients négatifs ===" << RESET << std::endl;
    
    // Test: 2*[1,3] + (-1)*[2,1] = [2,6] + [-2,-1] = [0,5]
    Vector<float> v1{1.0f, 3.0f};
    Vector<float> v2{2.0f, 1.0f};
    std::vector<Vector<float>> vectors = {v1, v2};
    std::vector<float> coeffs = {2.0f, -1.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    std::cout << "Coefficients: [2, -1]" << std::endl;
    
    Vector<float> result = linear_combination(vectors, coeffs);
    print_vector(result, "Résultat");
    std::cout << GREEN << "Attendu: [0, 5]" << RESET << std::endl;
}

void test_zero_coeff() {
    std::cout << YELLOW << "\n=== Test 4: Coefficient zéro ===" << RESET << std::endl;
    
    // Test: 0*[5,7] + 1*[2,3] = [0,0] + [2,3] = [2,3]
    Vector<float> v1{5.0f, 7.0f};
    Vector<float> v2{2.0f, 3.0f};
    std::vector<Vector<float>> vectors = {v1, v2};
    std::vector<float> coeffs = {0.0f, 1.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    std::cout << "Coefficients: [0, 1]" << std::endl;
    
    Vector<float> result = linear_combination(vectors, coeffs);
    print_vector(result, "Résultat");
    std::cout << GREEN << "Attendu: [2, 3]" << RESET << std::endl;
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 5: Cas d'erreur ===" << RESET << std::endl;
    
    try {
        // Test liste vide
        std::vector<Vector<float>> empty_vectors;
        std::vector<float> empty_coeffs;
        Vector<float> result = linear_combination(empty_vectors, empty_coeffs);
        std::cout << RED << "ERREUR: Exception attendue pour listes vides!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée pour listes vides: " << e.what() << RESET << std::endl;
    }
    
    try {
        // Test tailles différentes
        Vector<float> v1{1.0f, 2.0f};
        std::vector<Vector<float>> vectors = {v1};
        std::vector<float> coeffs = {1.0f, 2.0f}; // Trop de coefficients
        Vector<float> result = linear_combination(vectors, coeffs);
        std::cout << RED << "ERREUR: Exception attendue pour tailles différentes!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée pour tailles différentes: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "         TESTS COMBINAISON LINÉAIRE" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_basic_combination();
    test_three_vectors();
    test_negative_coeffs();
    test_zero_coeff();
    test_error_cases();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINÉS" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}