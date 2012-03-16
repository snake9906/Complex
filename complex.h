/**
    Библиотека для работы с комплексными числами

    Должны быть определены операторы:
        * сложения, check
        * вычитания, check
        * умножения, check
        * деления, check
        * вывода в поток, check
        * копирования, check
        * сравнения, check
        * вычисления модуля комплексного числа, check
        * нахождение сопряженного комплексного числа, check
        * функции извлечения степени. check
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>
#include <vector>

#include <cmath>

#include "exceptions.h"


class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double real);
    Complex(double real, double imag);
    Complex(const Complex& number);

    double get_real() const;
    double get_imag() const;
    std::vector<Complex> get_roots(const unsigned int n);

     /* Arithmetics */
    bool __eq__(const Complex& number) const;
     Complex __add__(const Complex& number) const;
     Complex __neg__() const;
     Complex __sub__(const Complex& number) const;
     Complex __mul__(const Complex& number) const;
     Complex __div__(const Complex& number) const;
     Complex __conjugate__() const;
     double __abs__() const;
     double __arg__() const;
     std::vector<Complex> __roots__(const unsigned int n);

     /* Operators */
     bool operator==(const Complex& number) const;
     Complex operator+(const Complex& number) const;
     Complex operator-() const;
     Complex operator-(const Complex& number) const;
     Complex operator*(const Complex& number) const;
     Complex operator/(const Complex& number) const;

     friend double abs(const Complex& number);
     friend double arg(const Complex& number);

     friend std::ostream& operator<<(std::ostream& cout_,
                                     const Complex& complexNumber);
};

#endif