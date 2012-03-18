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

    /**
      x.__copy__(y) <==> x = y
      */
    Complex& __copy__(const Complex& number);

    /* Setters */
    void set_real(double real);
    void set_imag(double imag);

    /* Getters */
    double get_real() const;
    double get_imag() const;

    std::vector<Complex> get_roots(const unsigned int n);

    /* Arithmetics */
    /* Boolean operations */

    /**
      x.__eq__(y) <==> x == y
      */
    bool __eq__(const Complex& number) const;

    /**
      x.__gt__(y) <==> x > y
      */
    bool __gt__(const Complex& number) const;

    /**
      x.__ge__(y) <==> x >= y
      */
    bool __ge__(const Complex& number) const;

    /**
      x.__lt__(y) <==> x < y
      */
    bool __lt__(const Complex& number) const;

    /**
      x.__le__(y) <==> x <= y
      */
    bool __le__(const Complex& number) const;

    Complex __conjugate__() const;

    /**
      x.__neg__() <==> -x
      */
    Complex __neg__() const;

    /**
      x.__abs__() <==> abs(x)
      */
    double __abs__() const;

    /**
      x.__arg__() <==> arg(x)
      */
    double __arg__() const;

    /**
      x.__add__(y) <==> x + y
      */
    Complex __add__(const Complex& number) const;

    /**
      x.__sub__(y) <==> x - y
      */
    Complex __sub__(const Complex& number) const;

    /**
      x.__mul__(y) <==> x * y
      */
    Complex __mul__(const Complex& number) const;

    /**
      x.__div__(y) <==> x / y
      */
    Complex __div__(const Complex& number) const;

    /**
      x.__radd__(y) <==> x += y
      */
    void __radd__(const Complex& number);

    /**
      x.__rsub__(y) <==> x -= y
      */
    void __rsub__(const Complex& number);

    /**
      x.__rmul__(y) <==> x *= y
      */
    void __rmul__(const Complex& number);

    /**
      x.__div__(y) <==> x /= y
      */
    void __rdiv__(const Complex& number);

    /**
      x.__pow__(n) <==> pow(x, n)
      */
    Complex __pow__(int n);

    /**
      x.__roots(n) <==> x.get_roots()
      it doesn't make any sense.
      */
    std::vector<Complex> __roots__(const unsigned int n);

    /* Operators */
    Complex operator=(const Complex& number);

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
    friend Complex pow(Complex number, unsigned int n);

    friend std::ostream& operator<<(std::ostream& cout_,
                                    const Complex& complexNumber);
};

#endif
