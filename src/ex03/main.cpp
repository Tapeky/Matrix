/**
 * -----------------------------------------------------------------------
 * Ex 03 - Dot Product
 * -----------------------------------------------------------------------
 * - Goal: Compute u·v = Σ(uᵢ * vᵢ)
 * - Method: Vector.dot(other) -> scalar
 * - Complexity: O(n) time, O(1) space
 * -----------------------------------------------------------------------
 */

#include "../../include/Vector.hpp"
#include <iostream>

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
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void interpret_dot_product(float result) {
    if (result > 0) {
        std::cout << GREEN << "→ Les vecteurs pointent dans des directions similaires" << RESET << std::endl;
    } else if (result == 0) {
        std::cout << YELLOW << "→ Les vecteurs sont perpendiculaires (angle de 90°)" << RESET << std::endl;
    } else {
        std::cout << RED << "→ Les vecteurs pointent dans des directions opposées" << RESET << std::endl;
    }
}

void test_basic_dot_products() {
    std::cout << YELLOW << "\n=== Test 1: Produits scalaires de base ===" << RESET << std::endl;
    
    Vector<float> v1{1.0f, 2.0f, 3.0f};
    Vector<float> v2{4.0f, 5.0f, 6.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.dot(v2);
    std::cout << BOLD << "v1 · v2 = " << result << RESET;
    std::cout << GREEN << " (attendu: 1×4 + 2×5 + 3×6 = 32)" << RESET << std::endl;
    interpret_dot_product(result);
}

void test_perpendicular_vectors() {
    std::cout << YELLOW << "\n=== Test 2: Vecteurs perpendiculaires ===" << RESET << std::endl;
    
    // Vecteurs perpendiculaires classiques
    Vector<float> v1{1.0f, 0.0f};
    Vector<float> v2{0.0f, 1.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.dot(v2);
    std::cout << BOLD << "v1 · v2 = " << result << RESET;
    std::cout << GREEN << " (attendu: 0)" << RESET << std::endl;
    interpret_dot_product(result);
    
    // Vecteurs perpendiculaires moins évidents
    Vector<float> v3{3.0f, 4.0f};
    Vector<float> v4{-4.0f, 3.0f};
    
    std::cout << std::endl;
    print_vector(v3, "v3");
    print_vector(v4, "v4");
    
    float result2 = v3.dot(v4);
    std::cout << BOLD << "v3 · v4 = " << result2 << RESET;
    std::cout << GREEN << " (attendu: 3×(-4) + 4×3 = 0)" << RESET << std::endl;
    interpret_dot_product(result2);
}

void test_opposite_vectors() {
    std::cout << YELLOW << "\n=== Test 3: Vecteurs opposés ===" << RESET << std::endl;
    
    Vector<float> v1{1.0f, 2.0f, 3.0f};
    Vector<float> v2{-1.0f, -2.0f, -3.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.dot(v2);
    std::cout << BOLD << "v1 · v2 = " << result << RESET;
    std::cout << GREEN << " (attendu: 1×(-1) + 2×(-2) + 3×(-3) = -14)" << RESET << std::endl;
    interpret_dot_product(result);
}

void test_self_dot_product() {
    std::cout << YELLOW << "\n=== Test 4: Produit scalaire avec soi-même ===" << RESET << std::endl;
    
    Vector<float> v{3.0f, 4.0f};
    
    print_vector(v, "v");
    
    float result = v.dot(v);
    std::cout << BOLD << "v · v = " << result << RESET;
    std::cout << GREEN << " (attendu: 3² + 4² = 25)" << RESET << std::endl;
    std::cout << BLUE << "→ C'est le carré de la longueur du vecteur!" << RESET << std::endl;
    std::cout << BLUE << "→ √(v · v) = √25 = 5 (longueur euclidienne)" << RESET << std::endl;
}

void test_zero_vector() {
    std::cout << YELLOW << "\n=== Test 5: Vecteur zéro ===" << RESET << std::endl;
    
    Vector<float> v1{1.0f, 2.0f, 3.0f};
    Vector<float> zero{0.0f, 0.0f, 0.0f};
    
    print_vector(v1, "v1");
    print_vector(zero, "zero");
    
    float result = v1.dot(zero);
    std::cout << BOLD << "v1 · zero = " << result << RESET;
    std::cout << GREEN << " (attendu: 0)" << RESET << std::endl;
    std::cout << BLUE << "→ Le vecteur zéro est perpendiculaire à tous les vecteurs" << RESET << std::endl;
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 6: Cas d'erreur ===" << RESET << std::endl;
    
    try {
        Vector<float> v1{1.0f, 2.0f};
        Vector<float> v2{3.0f, 4.0f, 5.0f}; // Taille différente
        std::cout << RED << "ERREUR: Exception attendue pour tailles différentes!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée pour tailles différentes: " << e.what() << RESET << std::endl;
    }
    
    try {
        Vector<float> empty1;
        Vector<float> empty2;
        std::cout << RED << "ERREUR: Exception attendue pour vecteurs vides!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception correctement levée pour vecteurs vides: " << e.what() << RESET << std::endl;
    }
}

void test_real_world_example() {
    std::cout << YELLOW << "\n=== Test 7: Exemple concret - Analyse de similarité ===" << RESET << std::endl;
    
    // Deux vecteurs représentant des préférences utilisateur (sur 5 critères)
    Vector<float> user1{5.0f, 3.0f, 4.0f, 2.0f, 1.0f}; // Préférences utilisateur 1
    Vector<float> user2{4.0f, 4.0f, 3.0f, 3.0f, 2.0f}; // Préférences utilisateur 2
    Vector<float> user3{1.0f, 2.0f, 1.0f, 4.0f, 5.0f}; // Préférences utilisateur 3
    
    print_vector(user1, "Utilisateur 1");
    print_vector(user2, "Utilisateur 2");
    print_vector(user3, "Utilisateur 3");
    
    float similarity_1_2 = user1.dot(user2);
    float similarity_1_3 = user1.dot(user3);
    
    std::cout << "\nAnalyse de similarité:" << std::endl;
    std::cout << BOLD << "Similarité 1-2: " << similarity_1_2 << RESET << std::endl;
    std::cout << BOLD << "Similarité 1-3: " << similarity_1_3 << RESET << std::endl;
    
    if (similarity_1_2 > similarity_1_3) {
        std::cout << GREEN << "→ L'utilisateur 1 a des goûts plus similaires à l'utilisateur 2" << RESET << std::endl;
    } else {
        std::cout << GREEN << "→ L'utilisateur 1 a des goûts plus similaires à l'utilisateur 3" << RESET << std::endl;
    }
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "              TESTS PRODUIT SCALAIRE" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_basic_dot_products();
    test_perpendicular_vectors();
    test_opposite_vectors();
    test_self_dot_product();
    test_zero_vector();
    test_error_cases();
    test_real_world_example();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINÉS" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}