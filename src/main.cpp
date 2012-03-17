/**
  Copyright [year] <Copyright Owner>
  */

/**
    Должны быть определены операторы:
        * сложения,
        * вычитания,
        * умножения,
        * деления,
        * вывода в поток,
        * копирования,
        * сравнения,
        * вычисления модуля комплексного числа,
        * нахождение сопряженного комплексного числа, check
        * функции извлечения степени. check
*/

#include <vector>

#include "include/complex.h"

void conjugate();
void find_roots();


int main() {
    conjugate();
    find_roots();
}


void conjugate() {
    Complex x(4, 5);
    std::cout << "The conjugate of the complex number " << x << " is " <<
                 x.__conjugate__() << "." << std::endl;
}

void find_roots() {
    Complex x(3, 2);
    std::vector<Complex> roots = x.get_roots(4);

    std::cout << "z^4 = " << x << std::endl;
    for (unsigned int i = 0; i < roots.size(); ++i) {
        std::cout << "z_" << i + 1 << " = " << roots[i] << std::endl;
    }

    // http://www.wolframalpha.com/input/?i=z^4=3+2i
}
