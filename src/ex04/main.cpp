/**
 * -----------------------------------------------------------------------
 * Ex 04 - Norm
 * -----------------------------------------------------------------------
 * - Goal: Vector magnitude calculations
 * - Methods: norm_1() (Manhattan), norm() (Euclidean), norm_inf() (max)
 * - Complexity: O(n) time, O(1) space
 * -----------------------------------------------------------------------
 */

#include "../../include/Vector.hpp"
#include <iostream>
#include <iomanip>

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

template<typename T>
void print_norms(const Vector<T>& v, const std::string& name) {
    print_vector(v, name);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "  " << YELLOW << "L1 (Manhattan): " << RESET << v.norm1() << std::endl;
    std::cout << "  " << GREEN << "L2 (Euclidienne): " << RESET << v.norm() << std::endl;
    std::cout << "  " << BLUE << "L∞ (Max): " << RESET << v.norm_inf() << std::endl;
    std::cout << std::endl;
}

void test_basic_norms() {
    std::cout << YELLOW << "\n=== Test 1: Normes de base ===" << RESET << std::endl;
    
    Vector<float> v1{3.0f, 4.0f};
    print_norms(v1, "v1");
    std::cout << GREEN << "Attendu: L1=7, L2=5, L∞=4" << RESET << std::endl;
    std::cout << BLUE << "→ Triangle rectangle classique 3-4-5!" << RESET << std::endl;
}

void test_negative_values() {
    std::cout << YELLOW << "\n=== Test 2: Valeurs négatives ===" << RESET << std::endl;
    
    Vector<float> v2{1.0f, -2.0f, 2.0f};
    print_norms(v2, "v2");
    std::cout << GREEN << "Attendu: L1=5, L2=3, L∞=2" << RESET << std::endl;
    std::cout << BLUE << "→ Les valeurs absolues sont prises en compte" << RESET << std::endl;
}

void test_unit_vectors() {
    std::cout << YELLOW << "\n=== Test 3: Vecteurs unitaires ===" << RESET << std::endl;
    
    Vector<float> e1{1.0f, 0.0f, 0.0f};
    Vector<float> e2{0.0f, 1.0f, 0.0f};
    Vector<float> e3{0.0f, 0.0f, 1.0f};
    
    print_norms(e1, "e1 (axe X)");
    print_norms(e2, "e2 (axe Y)");
    print_norms(e3, "e3 (axe Z)");
    
    std::cout << GREEN << "→ Tous les vecteurs unitaires ont une norme L2 = 1" << RESET << std::endl;
}

void test_zero_vector() {
    std::cout << YELLOW << "\n=== Test 4: Vecteur zéro ===" << RESET << std::endl;
    
    Vector<float> zero{0.0f, 0.0f, 0.0f};
    print_norms(zero, "vecteur zéro");
    std::cout << GREEN << "→ Toutes les normes du vecteur zéro = 0" << RESET << std::endl;
}

void test_comparison_norms() {
    std::cout << YELLOW << "\n=== Test 5: Comparaison des normes ===" << RESET << std::endl;
    
    Vector<float> v{1.0f, 1.0f, 1.0f, 1.0f};
    print_norms(v, "v (4 dimensions)");
    
    std::cout << BOLD << "Relation entre les normes:" << RESET << std::endl;
    std::cout << "  L∞ ≤ L2 ≤ L1 (inégalité générale)" << std::endl;
    std::cout << "  " << v.norm_inf() << " ≤ " << v.norm() << " ≤ " << v.norm1() << std::endl;
    
    if (v.norm_inf() <= v.norm() && v.norm() <= v.norm1()) {
        std::cout << GREEN << "✓ Inégalité respectée!" << RESET << std::endl;
    } else {
        std::cout << RED << "✗ Problème d'inégalité!" << RESET << std::endl;
    }
}

void test_large_values() {
    std::cout << YELLOW << "\n=== Test 6: Grandes valeurs ===" << RESET << std::endl;
    
    Vector<float> big{100.0f, -200.0f, 50.0f};
    print_norms(big, "big");
    std::cout << GREEN << "Attendu: L1=350, L2≈223.6, L∞=200" << RESET << std::endl;
}

void test_fractional_values() {
    std::cout << YELLOW << "\n=== Test 7: Valeurs fractionnaires ===" << RESET << std::endl;
    
    Vector<float> frac{0.5f, -0.3f, 0.8f};
    print_norms(frac, "frac");
    std::cout << GREEN << "Attendu: L1=1.6, L2≈0.98, L∞=0.8" << RESET << std::endl;
}

void test_error_cases() {
    std::cout << YELLOW << "\n=== Test 8: Cas d'erreur ===" << RESET << std::endl;
    
    try {
        Vector<float> empty;
        empty.norm1();
        std::cout << RED << "ERREUR: Exception attendue pour vecteur vide!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception L1 correctement levée: " << e.what() << RESET << std::endl;
    }
    
    try {
        Vector<float> empty;
        empty.norm();
        std::cout << RED << "ERREUR: Exception attendue pour vecteur vide!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception L2 correctement levée: " << e.what() << RESET << std::endl;
    }
    
    try {
        Vector<float> empty;
        empty.norm_inf();
        std::cout << RED << "ERREUR: Exception attendue pour vecteur vide!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception L∞ correctement levée: " << e.what() << RESET << std::endl;
    }
}

void test_real_world_examples() {
    std::cout << YELLOW << "\n=== Test 9: Exemples concrets ===" << RESET << std::endl;
    
    std::cout << BOLD << "🎮 Position d'un joueur en 3D:" << RESET << std::endl;
    Vector<float> player_pos{10.0f, 15.0f, 8.0f};
    print_norms(player_pos, "Position joueur");
    std::cout << BLUE << "→ Distance euclidienne du joueur à l'origine: " << player_pos.norm() << RESET << std::endl;
    
    std::cout << BOLD << "\n📊 Vecteur de performances:" << RESET << std::endl;
    Vector<float> performance{0.9f, 0.8f, 0.95f, 0.7f}; // 4 métriques normalisées
    print_norms(performance, "Performance");
    
    if (performance.norm_inf() >= 0.9f) {
        std::cout << GREEN << "→ Excellente performance (au moins une métrique ≥ 0.9)" << RESET << std::endl;
    } else if (performance.norm_inf() >= 0.7f) {
        std::cout << YELLOW << "→ Bonne performance" << RESET << std::endl;
    } else {
        std::cout << RED << "→ Performance à améliorer" << RESET << std::endl;
    }
    
    std::cout << BOLD << "\n🎯 Vecteur d'erreur:" << RESET << std::endl;
    Vector<float> error{0.01f, -0.02f, 0.005f, 0.015f};
    print_norms(error, "Erreur");
    std::cout << BLUE << "→ Erreur RMS (Root Mean Square): " << error.norm() / 2.0f << RESET << std::endl;
}

void test_normalization_preview() {
    std::cout << YELLOW << "\n=== Test 10: Aperçu normalisation ===" << RESET << std::endl;
    
    Vector<float> v{3.0f, 4.0f};
    print_norms(v, "v original");
    
    float length = v.norm();
    std::cout << BOLD << "Pour normaliser ce vecteur (longueur = 1):" << RESET << std::endl;
    std::cout << "  v_normalisé = v / ||v||₂ = v / " << length << std::endl;
    std::cout << "  v_normalisé = [" << 3.0f/length << ", " << 4.0f/length << "]" << std::endl;
    std::cout << "  v_normalisé = [0.6, 0.8]" << std::endl;
    std::cout << BLUE << "→ Vérification: 0.6² + 0.8² = 0.36 + 0.64 = 1.0 ✓" << RESET << std::endl;
}

int main() {
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "                TESTS NORMES" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    test_basic_norms();
    test_negative_values();
    test_unit_vectors();
    test_zero_vector();
    test_comparison_norms();
    test_large_values();
    test_fractional_values();
    test_error_cases();
    test_real_world_examples();
    test_normalization_preview();
    
    std::cout << MAGENTA << "\n===============================================" << RESET << std::endl;
    std::cout << MAGENTA << "               TESTS TERMINÉS" << RESET << std::endl;
    std::cout << MAGENTA << "===============================================" << RESET << std::endl;
    
    return 0;
}