/**
  Copyright [year] <Copyright Owner>
  */

#include <vector>

#include "include/complex.h"


void arithmetics();
void copy();
void absolute_value();
void comparison();
void conjugate();
void find_roots();


int main() {
    arithmetics();
    copy();
    comparison();
    absolute_value();
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
}

void comparison() {
    Complex a(3, 4), b(2, 3);
    Complex c(a);

    std::boolalpha(std::cout);
    std::cout << a << " == " << b << " is " << (a == b) << std::endl;
    std::cout << a << " == " << c << " is " << (a == c) << std::endl;
}

void absolute_value() {
    Complex x = Complex(3, 14);

    // http://www.wolframalpha.com/input/?i=abs%283%2B14i%29
    std::cout << abs(x) << std::endl;
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
