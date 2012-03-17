/**
  Copyright [year] <Copyright Owner>
  */

/**
    Должны быть определены операторы:
        * сложения, check
        * вычитания, check
        * умножения, check
        * деления, check
        * вывода в поток, check
        * копирования, check
        * сравнения,
        * вычисления модуля комплексного числа,
        * нахождение сопряженного комплексного числа, check
        * функции извлечения степени. check
*/

#include <vector>

#include "include/complex.h"

void arithmetics();

void copy();
void conjugate();
void find_roots();


int main() {
    arithmetics();
    copy();

    conjugate();
    find_roots();
}


void arithmetics() {
    Complex a, b;

    // overloaded operator=
    a = Complex(10, 10);
    b = Complex(2, 3);

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;

    // http://www.wolframalpha.com/input/?i=(2%2B3i)*(10%2B10i)
    std::cout << a << " * " << b << " = " << a * b << std::endl;

    // http://www.wolframalpha.com/input/?i=%282%2B3i%29%2F%2810%2B10i%29
    std::cout << a << " / " << b << " = " << a / b << std::endl;
}

void copy() {
    Complex a;
    a = Complex(1, -4);

    Complex b(a);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << a << " == " << b << " is "
              << std::boolalpha << (a == b) << std::endl;
}

void conjugate() {
    Complex x(4, 5);
    std::cout << "The conjugate of the complex number " << x << " is " <<
                 x.__conjugate__() << "." << std::endl;
}

void find_roots() {
    Complex x(3, 2);
    std::vector<Complex> roots = x.get_roots(4);

    // http://www.wolframalpha.com/input/?i=z%5E4%3D3%2B2i
    std::cout << "z^4 = " << x << std::endl;
    for (unsigned int i = 0; i < roots.size(); ++i) {
        std::cout << "z_" << i + 1 << " = " << roots[i] << std::endl;
    }
}
