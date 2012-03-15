#include "complex.h"

#include <iostream>


int main() {
    Complex x(-2, -3);
    Complex y(x);

//    std::cout << (Complex(3, 2) / Complex(2, 3)) << std::endl;
//    std::cout << abs(Complex(3, 2)) << std::endl;
//    std::cout << Complex(3, 2).__conjugate__() << std::endl;
//    std::cout << arg(Complex(1, 0)) << std::endl;

    std::cout << Complex(3, 2) << std::endl;
    std::vector<Complex> roots = Complex(3, 2).get_roots(4);

    for (unsigned int i = 0; i < roots.size(); ++i) {
        std::cout << roots[i] << std::endl;
    }
}
