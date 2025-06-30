#include "../include/Matrix.hpp"
#include "../include/Vector.hpp"
#include "../include/Utils.hpp"

  int main() {
      // Test Vector to Matrix
      Vector<int> v{1, 2, 3, 4, 5, 6};
      std::cout << "Vector original: ";
      v.print();
      std::cout << std::endl;

      Matrix<int> m = reshape(v, 2, 3);
      std::cout << "Matrix 2x3:" << std::endl;
      m.print();

      // Test Matrix to Vector
      Vector<int> v2 = reshape(m);
      std::cout << "Retour en Vector: ";
      v2.print();
      std::cout << std::endl;

      return 0;
  }