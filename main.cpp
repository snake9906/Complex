#include "complex.h"

#include <iostream>


int main() {
    Complex x(1, 1);
    Complex y = x;
    y.set_imag(100);

    Complex(0, 1).__arg__();
    std::cout << (Complex(3, 2) / Complex(0, 1)) << std::endl;
    std::cout << abs(Complex(3, 2)) << std::endl;
    std::cout << Complex(3, 2).__conjugate__() << std::endl;
    std::cout << arg(Complex(1, 0)) << std::endl;

    std::cout << y << std::endl;
    std::cout << x << std::endl;
    std::cout << Complex(1, 1) << std::endl;
    std::vector<Complex> roots = Complex(1, 1).get_roots(4);

    for (unsigned int i = 0; i < roots.size(); ++i) {
        std::cout << roots[i] << std::endl;
    }
}
