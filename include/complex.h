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

#include "include/exceptions.h"


class Complex {
private:
    double real;
    double imag;

public:
    /* Constructors */
    Complex();
    Complex(double real);
    Complex(double real, double imag);
    Complex(const Complex& number);

    /* Setters */
    void set_real(double real);
    void set_imag(double imag);

    /* Getters */
    double get_real() const;
    double get_imag() const;

    std::vector<Complex> get_roots(const unsigned int n);

    /* Arithmetics */
    /* Boolean operations */
    bool __eq__(const Complex& number) const;

    bool __gt__(const Complex& number) const;
    bool __ge__(const Complex& number) const;
    bool __lt__(const Complex& number) const;
    bool __le__(const Complex& number) const;

    Complex __neg__() const;
    Complex __conjugate__() const;
    double __abs__() const;
    double __arg__() const;

    Complex __add__(const Complex& number) const;
    Complex __sub__(const Complex& number) const;
    Complex __mul__(const Complex& number) const;
    Complex __div__(const Complex& number) const;

    void __radd__(const Complex& number);
    void __rsub__(const Complex& number);
    void __rmul__(const Complex& number);
    void __rdiv__(const Complex& number);

    Complex __pow__(int n);
    std::vector<Complex> __roots__(const unsigned int n);

    /* Operators */
    Complex& operator=(const Complex& number);

    /* Boolean */
    bool operator==(const Complex& number) const;

    bool operator>(const Complex& number) const;
    bool operator<(const Complex& number) const;
    bool operator>=(const Complex& number) const;
    bool operator<=(const Complex& number) const;

    Complex operator-() const;

    Complex operator+(const Complex& number) const;
    Complex operator-(const Complex& number) const;
    Complex operator*(const Complex& number) const;
    Complex operator/(const Complex& number) const;

    void operator+=(const Complex& number);
    void operator-=(const Complex& number);
    void operator*=(const Complex& number);
    void operator/=(const Complex& number);

    /* Friend functions */
    friend double abs(const Complex& number);
    friend double arg(const Complex& number);

    friend std::ostream& operator<<(std::ostream& cout_,
                                    const Complex& complexNumber);
};

#endif
