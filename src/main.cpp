/**
  Copyright [year] <Copyright Owner>
  */

#include <vector>

#include "include/complex.h"


void find_roots() {
    Complex x(3, 2);
    std::vector<Complex> roots = x.get_roots(4);

    std::cout << "z^4 = " << x << std::endl;
    for (unsigned int i = 0; i < roots.size(); ++i) {
        std::cout << "z_" << i + 1 << " = " << roots[i] << std::endl;
    }

    // http://www.wolframalpha.com/input/?i=z^4=3+2i
}


int main() {
    find_roots();
}
