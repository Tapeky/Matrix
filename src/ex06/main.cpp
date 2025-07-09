/**
 * -----------------------------------------------------------------------
 * Ex 06 - Cross Product
 * -----------------------------------------------------------------------
 * - Goal: 3D vector perpendicular product u×v
 * - Function: cross_product(u, v) -> Vector (3D only)
 * - Formula: [u₂v₃-u₃v₂, u₃v₁-u₁v₃, u₁v₂-u₂v₁]
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
        std::cout << std::fixed << std::setprecision(3) << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void test_basic_cross_products() {
    std::cout << YELLOW << "\n=== Test 1: Produits vectoriels de base ===" << RESET << std::endl;
    
    Vector<float> u{1.0f, 2.0f, 3.0f};
    Vector<float> v{4.0f, 5.0f, 6.0f};
    
    print_vector(u, "u");
    print_vector(v, "v");
    
    Vector<float> result = u.cross_product(v);
    print_vector(result, "u x v");
    
    // Calcul manuel: [2*6-3*5, 3*4-1*6, 1*5-2*4] = [12-15, 12-6, 5-8] = [-3, 6, -3]
    std::cout << GREEN << "Attendu: [-3, 6, -3]" << RESET << std::endl;
}

void test_unit_vectors() {
    std::cout << YELLOW << "\n=== Test 2: Vecteurs unitaires (axes) ===" << RESET << std::endl;
    
    Vector<float> i{1.0f, 0.0f, 0.0f};  // Axe X
    Vector<float> j{0.0f, 1.0f, 0.0f};  // Axe Y
    Vector<float> k{0.0f, 0.0f, 1.0f};  // Axe Z
    
    print_vector(i, "i (axe X)");
    print_vector(j, "j (axe Y)");
    print_vector(k, "k (axe Z)");
    
    std::cout << "\nProduits vectoriels des axes:" << std::endl;
    
    Vector<float> i_cross_j = i.cross_product(j);
    print_vector(i_cross_j, "i x j");
    std::cout << GREEN << "Attendu: [0, 0, 1] (axe Z)" << RESET << std::endl;
    
    Vector<float> j_cross_k = j.cross_product(k);
    print_vector(j_cross_k, "j x k");
    std::cout << GREEN << "Attendu: [1, 0, 0] (axe X)" << RESET << std::endl;
    
    Vector<float> k_cross_i = k.cross_product(i);
    print_vector(k_cross_i, "k x i");
    std::cout << GREEN << "Attendu: [0, 1, 0] (axe Y)" << RESET << std::endl;
}

void test_anticommutative_property() {
    std::cout << YELLOW << "\n=== Test 3: Propriete anti-commutative ===" << RESET << std::endl;
    
    Vector<float> u{2.0f, 3.0f, 1.0f};
    Vector<float> v{1.0f, 4.0f, 2.0f};
    
    print_vector(u, "u");
    print_vector(v, "v");
    
    Vector<float> u_cross_v = u.cross_product(v);
    Vector<float> v_cross_u = v.cross_product(u);
    
    print_vector(u_cross_v, "u x v");
    print_vector(v_cross_u, "v x u");
    
    std::cout << GREEN << "Verification: u x v = -(v x u)" << RESET << std::endl;
    std::cout << "u x v + v x u = ";
    for (size_t i = 0; i < 3; ++i) {
        std::cout << (u_cross_v[i] + v_cross_u[i]);
        if (i < 2) std::cout << ", ";
    }
    std::cout << " (doit etre proche de [0, 0, 0])" << std::endl;
}

void test_parallel_vectors() {
    std::cout << YELLOW << "\n=== Test 4: Vecteurs paralleles ===" << RESET << std::endl;
    
    Vector<float> u{3.0f, 6.0f, 9.0f};
    Vector<float> v{1.0f, 2.0f, 3.0f};  // v = u/3
    
    print_vector(u, "u");
    print_vector(v, "v (= u/3)");
    
    Vector<float> result = u.cross_product(v);
    print_vector(result, "u x v");
    std::cout << GREEN << "Attendu: [0, 0, 0] (vecteurs paralleles)" << RESET << std::endl;
}

void test_self_cross_product() {
    std::cout << YELLOW << "\n=== Test 5: Produit vectoriel avec soi-meme ===" << RESET << std::endl;
    
    Vector<float> u{5.0f, 3.0f, 8.0f};
    
    print_vector(u, "u");
    
    Vector<float> result = u.cross_product(u);
    print_vector(result, "u x u");
    std::cout << GREEN << "Attendu: [0, 0, 0] (vecteur avec lui-meme)" << RESET << std::endl;
}

void test_perpendicularity() {
    std::cout << YELLOW << "\n=== Test 6: Verification perpendicularite ===" << RESET << std::endl;
    
    Vector<float> u{1.0f, 2.0f, 3.0f};
    Vector<float> v{4.0f, 5.0f, 6.0f};
    
    print_vector(u, "u");
    print_vector(v, "v");
    
    Vector<float> w = u.cross_product(v);
    print_vector(w, "w = u x v");
    
    // Verification que w est perpendiculaire a u et v
    float dot_w_u = w.dot(u);
    float dot_w_v = w.dot(v);
    
    std::cout << "Verification perpendicularite:" << std::endl;
    std::cout << "w . u = " << dot_w_u << " (doit etre 0)" << std::endl;
    std::cout << "w . v = " << dot_w_v << " (doit etre 0)" << std::endl;
    
    if (std::abs(dot_w_u) < 1e-6f && std::abs(dot_w_v) < 1e-6f) {
        std::cout << GREEN << "OK w est perpendiculaire a u et v" << RESET << std::endl;
    } else {
        std::cout << RED << "ERREUR w n'est pas perpendiculaire!" << RESET << std::endl;
    }
}

void test_magnitude_formula() {
    std::cout << YELLOW << "\n=== Test 7: Verification formule magnitude ===" << RESET << std::endl;
    
    Vector<float> u{3.0f, 0.0f, 0.0f};
    Vector<float> v{0.0f, 4.0f, 0.0f};
    
    print_vector(u, "u");
    print_vector(v, "v");
    
    Vector<float> w = u.cross_product(v);
    print_vector(w, "w = u x v");
    
    float norm_u = u.norm();
    float norm_v = v.norm();
    float norm_w = w.norm();
    
    // Pour vecteurs perpendiculaires: ||u x v|| = ||u|| * ||v|| * sin(90°) = ||u|| * ||v|| * 1
    float expected_norm = norm_u * norm_v;
    
    std::cout << "||u|| = " << norm_u << std::endl;
    std::cout << "||v|| = " << norm_v << std::endl;
    std::cout << "||w|| = " << norm_w << std::endl;
    std::cout << "||u|| * ||v|| = " << expected_norm << std::endl;
    
    if (std::abs(norm_w - expected_norm) < 1e-6f) {
        std::cout << GREEN << "OK ||u x v|| = ||u|| * ||v|| (vecteurs perpendiculaires)" << RESET << std::endl;
    } else {
        std::cout << RED << "ERREUR dans la formule de magnitude!" << RESET << std::endl;
    }
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 8: Cas d'erreur ===" << RESET << std::endl;
    
    try {
        Vector<float> u{1.0f, 2.0f};  // Taille 2
        Vector<float> v{3.0f, 4.0f, 5.0f};  // Taille 3
        u.cross_product(v);
        std::cout << RED << "ERREUR: Exception attendue pour taille 2!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception correctement levee pour taille 2: " << e.what() << RESET << std::endl;
    }
    
    try {
        Vector<float> u{1.0f, 2.0f, 3.0f};  // Taille 3
        Vector<float> v{4.0f, 5.0f, 6.0f, 7.0f};  // Taille 4
        u.cross_product(v);
        std::cout << RED << "ERREUR: Exception attendue pour taille 4!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception correctement levee pour taille 4: " << e.what() << RESET << std::endl;
    }
    
    try {
        Vector<float> empty1;
        Vector<float> empty2;
        empty1.cross_product(empty2);
        std::cout << RED << "ERREUR: Exception attendue pour vecteurs vides!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "OK Exception correctement levee pour vecteurs vides: " << e.what() << RESET << std::endl;
    }
}

void test_real_world_example() {
    std::cout << YELLOW << "\n=== Test 9: Exemple concret - Normal a une surface ===" << RESET << std::endl;
    
    // Deux vecteurs definissant un plan
    Vector<float> edge1{1.0f, 0.0f, 0.0f};  // Arete 1
    Vector<float> edge2{0.0f, 1.0f, 0.0f};  // Arete 2
    
    print_vector(edge1, "Arete 1");
    print_vector(edge2, "Arete 2");
    
    // Normal au plan = produit vectoriel
    Vector<float> normal = edge1.cross_product(edge2);
    print_vector(normal, "Normal au plan");
    
    std::cout << GREEN << "-> Normal pointe vers l'axe Z (plan XY)" << RESET << std::endl;
    
    // Exemple 2: Triangle dans l'espace
    Vector<float> v1{2.0f, 1.0f, 0.0f};
    Vector<float> v2{1.0f, 3.0f, 0.0f};
    
    print_vector(v1, "Vecteur 1");
    print_vector(v2, "Vecteur 2");
    
    Vector<float> normal2 = v1.cross_product(v2);
    print_vector(normal2, "Normal triangle");
    
    std::cout << BLUE << "-> Utilise en infographie pour l'eclairage!" << RESET << std::endl;
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "             TESTS PRODUIT VECTORIEL" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_basic_cross_products();
    test_unit_vectors();
    test_anticommutative_property();
    test_parallel_vectors();
    test_self_cross_product();
    test_perpendicularity();
    test_magnitude_formula();
    test_error_cases();
    test_real_world_example();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINES" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}