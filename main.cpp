/**
  Copyright [year] <Copyright Owner>
  */

#include <vector>

#include "include/complex.h"


int main() {
    std::vector<Complex> roots = Complex(1, 1).get_roots(4);

    for (unsigned int i = 0; i < roots.size(); ++i) {
        std::cout << roots[i] << std::endl;
    }

    Complex x(1, 1);
    Complex y(2, 2);
    Complex z = x / y;
    std::cout << z << std::endl;

    std::cout << x << std::endl;
    x /= y;
    std::cout << x << std::endl;
}
