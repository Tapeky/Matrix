/**
 * -----------------------------------------------------------------------
 * Ex 05 - Cosine
 * -----------------------------------------------------------------------
 * - Goal: cos(angle) = (u*v)/(||u|| * ||v||)
 * - Function: angle_cos(u, v) -> f32
 * - Complexity: O(n) time, O(1) space
 * -----------------------------------------------------------------------
 */

#include "../../include/Vector.hpp"
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
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void interpret_cosine(float cos_value) {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "  cos(angle) = " << cos_value;
    
    if (cos_value > 0.9f) {
        std::cout << GREEN << " -> Vecteurs tres similaires (angle ~ 0 degres)" << RESET << std::endl;
    } else if (cos_value > 0.5f) {
        std::cout << GREEN << " -> Angle aigu (angle < 90 degres)" << RESET << std::endl;
    } else if (cos_value > 0.1f) {
        std::cout << YELLOW << " -> Angle modere" << RESET << std::endl;
    } else if (cos_value > -0.1f) {
        std::cout << YELLOW << " -> Vecteurs quasi perpendiculaires (angle ~ 90 degres)" << RESET << std::endl;
    } else if (cos_value > -0.5f) {
        std::cout << BLUE << " -> Angle obtus (angle > 90 degres)" << RESET << std::endl;
    } else if (cos_value > -0.9f) {
        std::cout << RED << " -> Vecteurs opposes" << RESET << std::endl;
    } else {
        std::cout << RED << " -> Vecteurs tres opposes (angle ~ 180 degres)" << RESET << std::endl;
    }
}

void test_identical_vectors() {
    std::cout << YELLOW << "\n=== Test 1: Vecteurs identiques ===" << RESET << std::endl;
    
    Vector<float> v1{3.0f, 4.0f};
    Vector<float> v2{3.0f, 4.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.angle_cos(v2);
    interpret_cosine(result);
    std::cout << GREEN << "Attendu: cos(angle) = 1.0 (angle = 0 degres)" << RESET << std::endl;
}

void test_perpendicular_vectors() {
    std::cout << YELLOW << "\n=== Test 2: Vecteurs perpendiculaires ===" << RESET << std::endl;
    
    Vector<float> v1{1.0f, 0.0f};
    Vector<float> v2{0.0f, 1.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.angle_cos(v2);
    interpret_cosine(result);
    std::cout << GREEN << "Attendu: cos(angle) = 0.0 (angle = 90 degres)" << RESET << std::endl;
    
    // Test avec vecteurs perpendiculaires moins evidents
    std::cout << std::endl;
    Vector<float> v3{3.0f, 4.0f};
    Vector<float> v4{-4.0f, 3.0f};
    
    print_vector(v3, "v3");
    print_vector(v4, "v4");
    
    float result2 = v3.angle_cos(v4);
    interpret_cosine(result2);
    std::cout << GREEN << "Attendu: cos(angle) = 0.0 (perpendiculaires)" << RESET << std::endl;
}

void test_opposite_vectors() {
    std::cout << YELLOW << "\n=== Test 3: Vecteurs opposes ===" << RESET << std::endl;
    
    Vector<float> v1{1.0f, 2.0f, 3.0f};
    Vector<float> v2{-1.0f, -2.0f, -3.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.angle_cos(v2);
    interpret_cosine(result);
    std::cout << GREEN << "Attendu: cos(angle) = -1.0 (angle = 180 degres)" << RESET << std::endl;
}

void test_acute_angle() {
    std::cout << YELLOW << "\n=== Test 4: Angle aigu ===" << RESET << std::endl;
    
    Vector<float> v1{1.0f, 0.0f};
    Vector<float> v2{1.0f, 1.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.angle_cos(v2);
    interpret_cosine(result);
    std::cout << GREEN << "Attendu: cos(angle) = sqrt(2)/2 ~ 0.707 (angle = 45 degres)" << RESET << std::endl;
}

void test_obtuse_angle() {
    std::cout << YELLOW << "\n=== Test 5: Angle obtus ===" << RESET << std::endl;
    
    Vector<float> v1{1.0f, 0.0f};
    Vector<float> v2{-1.0f, 1.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float result = v1.angle_cos(v2);
    interpret_cosine(result);
    std::cout << GREEN << "Attendu: cos(angle) = -sqrt(2)/2 ~ -0.707 (angle = 135 degres)" << RESET << std::endl;
}

void test_unit_vectors() {
    std::cout << YELLOW << "\n=== Test 6: Vecteurs unitaires ===" << RESET << std::endl;
    
    Vector<float> e1{1.0f, 0.0f, 0.0f};
    Vector<float> e2{0.0f, 1.0f, 0.0f};
    Vector<float> e3{0.0f, 0.0f, 1.0f};
    
    print_vector(e1, "e1 (axe X)");
    print_vector(e2, "e2 (axe Y)");
    print_vector(e3, "e3 (axe Z)");
    
    std::cout << "\nTests entre axes:" << std::endl;
    std::cout << "e1 * e2: cos(angle) = " << e1.angle_cos(e2) << " (90 degres)" << std::endl;
    std::cout << "e1 * e3: cos(angle) = " << e1.angle_cos(e3) << " (90 degres)" << std::endl;
    std::cout << "e2 * e3: cos(angle) = " << e2.angle_cos(e3) << " (90 degres)" << std::endl;
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 7: Cas d'erreur ===" << RESET << std::endl;
    
    try {
        Vector<float> v1{1.0f, 2.0f};
        Vector<float> v2{3.0f, 4.0f, 5.0f}; // Taille differente
        v1.angle_cos(v2);
        std::cout << RED << "ERREUR: Exception attendue pour tailles differentes!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception correctement levee pour tailles differentes: " << e.what() << RESET << std::endl;
    }
    
    try {
        Vector<float> zero{0.0f, 0.0f};
        Vector<float> v{1.0f, 2.0f};
        zero.angle_cos(v);
        std::cout << RED << "ERREUR: Exception attendue pour vecteur zero!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception correctement levee pour vecteur zero: " << e.what() << RESET << std::endl;
    }
    
    try {
        Vector<float> empty1;
        Vector<float> empty2;
        empty1.angle_cos(empty2);
        std::cout << RED << "ERREUR: Exception attendue pour vecteurs vides!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception correctement levee pour vecteurs vides: " << e.what() << RESET << std::endl;
    }
}

void test_real_world_example() {
    std::cout << YELLOW << "\n=== Test 8: Exemple concret - Analyse de similarite ===" << RESET << std::endl;
    
    // Preferences d'utilisateurs (normalisees)
    Vector<float> user1{0.8f, 0.6f, 0.9f, 0.3f};  // Utilisateur 1
    Vector<float> user2{0.7f, 0.5f, 0.8f, 0.4f};  // Utilisateur 2 (similaire)
    Vector<float> user3{0.2f, 0.9f, 0.1f, 0.8f};  // Utilisateur 3 (different)
    
    print_vector(user1, "Utilisateur 1");
    print_vector(user2, "Utilisateur 2");
    print_vector(user3, "Utilisateur 3");
    
    float sim_1_2 = user1.angle_cos(user2);
    float sim_1_3 = user1.angle_cos(user3);
    
    std::cout << "\nAnalyse de similarite:" << std::endl;
    std::cout << "Similarite 1-2: ";
    interpret_cosine(sim_1_2);
    std::cout << "Similarite 1-3: ";
    interpret_cosine(sim_1_3);
    
    if (sim_1_2 > sim_1_3) {
        std::cout << GREEN << "-> L'utilisateur 1 est plus similaire a l'utilisateur 2" << RESET << std::endl;
    } else {
        std::cout << BLUE << "-> L'utilisateur 1 est plus similaire a l'utilisateur 3" << RESET << std::endl;
    }
}

void test_validation_examples() {
    std::cout << YELLOW << "\n=== Test 9: Validation mathematique ===" << RESET << std::endl;
    
    // Test avec triangle 3-4-5
    Vector<float> v1{3.0f, 4.0f};
    Vector<float> v2{5.0f, 0.0f};
    
    print_vector(v1, "v1");
    print_vector(v2, "v2");
    
    float cos_theta = v1.angle_cos(v2);
    
    std::cout << "Calcul manuel:" << std::endl;
    std::cout << "  v1*v2 = " << v1.dot(v2) << std::endl;
    std::cout << "  ||v1|| = " << v1.norm() << std::endl;
    std::cout << "  ||v2|| = " << v2.norm() << std::endl;
    std::cout << "  cos(angle) = " << v1.dot(v2) << " / (" << v1.norm() << " x " << v2.norm() << ")" << std::endl;
    std::cout << "  cos(angle) = " << cos_theta << std::endl;
    
    // Verification que -1 <= cos(angle) <= 1
    if (cos_theta >= -1.0f && cos_theta <= 1.0f) {
        std::cout << GREEN << "OK Resultat dans l'intervalle [-1, 1]" << RESET << std::endl;
    } else {
        std::cout << RED << "ERREUR Resultat hors intervalle [-1, 1]!" << RESET << std::endl;
    }
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "              TESTS COSINUS D'ANGLE" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_identical_vectors();
    test_perpendicular_vectors();
    test_opposite_vectors();
    test_acute_angle();
    test_obtuse_angle();
    test_unit_vectors();
    test_error_cases();
    test_real_world_example();
    test_validation_examples();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINES" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}