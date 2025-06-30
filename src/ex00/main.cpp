/**
 * Exercise 00 - Add, Subtract, Scale
 * ==================================
 * 
 * Goal: Test basic vector/matrix operations
 * - add() : addition of vectors/matrices
 * - sub() : subtraction of vectors/matrices  
 * - scl() : scalar multiplication
 * 
 * Complexity: O(n) time, O(1) space (modify in place)
 */

#include "../../include/Vector.hpp"
#include "../../include/Matrix.hpp"
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

void print_header(const std::string& title) {
    std::cout << "\n" << BOLD << CYAN << "=" << std::string(50, '=') << "=" << RESET << std::endl;
    std::cout << BOLD << CYAN << "  " << title << RESET << std::endl;
    std::cout << BOLD << CYAN << "=" << std::string(50, '=') << "=" << RESET << std::endl;
}

void print_section(const std::string& title) {
    std::cout << "\n" << BOLD << YELLOW << "--- " << title << " ---" << RESET << std::endl;
}

void print_test(const std::string& operation, const std::string& expected) {
    std::cout << BOLD << GREEN << "✓ " << operation << RESET;
    if (!expected.empty()) {
        std::cout << BOLD << WHITE << " → " << RESET << MAGENTA << expected << RESET;
    }
    std::cout << std::endl;
}

void print_result() {
    std::cout << BLUE << "  Result: " << RESET;
}

void print_expected(const std::string& expected) {
    std::cout << "  " << BOLD << WHITE << "Expected: " << RESET << MAGENTA << expected << RESET << std::endl;
}

int main() {
    print_header("Exercise 00: Add, Subtract, Scale");
    
    // ======================
    // VECTOR OPERATIONS
    // ======================
    print_section("Vector Operations");
    
    Vector<float> v1{1.0f, 2.0f, 3.0f};
    Vector<float> v2{4.0f, 5.0f, 6.0f};
    
    std::cout << BOLD << "Input vectors:" << RESET << std::endl;
    std::cout << "  v1 = " << CYAN;
    v1.print();
    std::cout << RESET << std::endl;
    std::cout << "  v2 = " << CYAN;
    v2.print();
    std::cout << RESET << std::endl << std::endl;
    
    // Test addition
    print_test("Addition", "v1 + v2");
    Vector<float> v_add = v1;
    v_add.add(v2);
    print_result();
    v_add.print();
    std::cout << RESET << std::endl;
    print_expected("[5, 7, 9]");
    
    std::cout << std::endl;
    
    // Test subtraction
    print_test("Subtraction", "v1 - v2");
    Vector<float> v_sub = v1;
    v_sub.sub(v2);
    print_result();
    v_sub.print();
    std::cout << RESET << std::endl;
    print_expected("[-3, -3, -3]");
    
    std::cout << std::endl;
    
    // Test scalar multiplication
    print_test("Scalar multiplication", "v1 * 2.5");
    Vector<float> v_scl = v1;
    v_scl.scl(2.5f);
    print_result();
    v_scl.print();
    std::cout << RESET << std::endl;
    print_expected("[2.5, 5, 7.5]");
    
    // ======================
    // MATRIX OPERATIONS
    // ======================
    print_section("Matrix Operations");
    
    Matrix<float> m1(2, 3, 1.0f);
    Matrix<float> m2(2, 3, 2.0f);
    
    std::cout << BOLD << "Input matrices:" << RESET << std::endl;
    std::cout << "  m1 =" << std::endl;
    m1.print();
    std::cout << std::endl;
    std::cout << "  m2 =" << std::endl;
    m2.print();
    std::cout << std::endl;
    
    // Test matrix addition
    print_test("Matrix Addition", "m1 + m2");
    Matrix<float> m_add = m1;
    m_add.add(m2);
    print_result();
    std::cout << std::endl;
    m_add.print();
    print_expected("all elements = 3.0");
    
    std::cout << std::endl;
    
    // Test matrix subtraction
    print_test("Matrix Subtraction", "m1 - m2");
    Matrix<float> m_sub = m1;
    m_sub.sub(m2);
    print_result();
    std::cout << std::endl;
    m_sub.print();
    print_expected("all elements = -1.0");
    
    std::cout << std::endl;
    
    // Test matrix scalar multiplication
    print_test("Matrix Scalar multiplication", "m1 * 3.0");
    Matrix<float> m_scl = m1;
    m_scl.scl(3.0f);
    print_result();
    std::cout << std::endl;
    m_scl.print();
    print_expected("all elements = 3.0");
    
    // ======================
    // EDGE CASES
    // ======================
    print_section("Advanced Test Cases");
    
    Matrix<float> m3(2, 2);
    m3(0, 0) = 1.0f; m3(0, 1) = 2.0f;
    m3(1, 0) = 3.0f; m3(1, 1) = 4.0f;
    
    Matrix<float> m4(2, 2);
    m4(0, 0) = 0.5f; m4(0, 1) = 1.5f;
    m4(1, 0) = 2.5f; m4(1, 1) = 3.5f;
    
    std::cout << BOLD << "Custom matrices:" << RESET << std::endl;
    std::cout << "  m3 =" << std::endl;
    m3.print();
    std::cout << std::endl;
    std::cout << "  m4 =" << std::endl;
    m4.print();
    std::cout << std::endl;
    
    print_test("Custom matrix addition", "m3 + m4");
    m3.add(m4);
    print_result();
    std::cout << std::endl;
    m3.print();
    print_expected("[1.5, 3.5], [5.5, 7.5]");
        
    return 0;
}