/**
  Copyright [year] <Copyright Owner>
  */

#include "complex.h"


Complex::Complex() {
    this->real = 0;
    this->imag = 0;
}

Complex::Complex(double real) {
    this->real = real;
    this->imag = 0;
}

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

Complex::Complex(const Complex& number) {
    this->real = number.real;
    this->imag = number.imag;
}

double Complex::get_real() const {
    return this->real;
}

double Complex::get_imag() const {
    return this->imag;
}

std::vector<Complex> Complex::get_roots(const unsigned int n) {
    return this->__roots__(n);
}

/* Complex arithmetics */

Complex Complex::__add__(const Complex number) const {
    return Complex(this->real + number.real, this->imag + number.imag);
}

Complex Complex::__neg__() const {
    return Complex(-this->real, -this->imag);
}

Complex Complex::__sub__(const Complex number) const {
    return this->__add__(number.__neg__());
}

bool Complex::__eq__(const Complex number) const {
    return this->real == number.real && this->imag == number.imag;
}

Complex Complex::__mul__(const Complex number) const {
    return Complex(this->real * number.real - this->imag * number.imag,
                   this->imag * number.real + this->real * number.imag);
}

Complex Complex::__div__(const Complex number) const {
    if (number.__eq__(Complex(0, 0))) {
        throw DivideByZeroException();
    }

    double real, imag;
    real = this->real * number.real + this->imag * number.imag;
    imag = this->imag * number.real - this->real * number.imag;

    double t = pow(number.real, 2) + pow(number.imag, 2);
    real /= t;
    imag /= t;

    return Complex(real, imag);
}

double Complex::__arg__() const {
    double phi = atan(this->imag / this->real);

    if (this->real < 0) {
        if (this->imag >= 0) {
            phi += M_PI;
        } else {
            phi -= M_PI;
        }
    } else if (this->real == 0) {
        if (this->imag == 0) {
            throw IndeterminateValueException();
        }

        phi = M_PI / 2;
        if (this->imag < 0) {
            phi = -phi;
        }
    }

    return phi;
}

std::vector<Complex> Complex::__roots__(const unsigned int n) {
    std::vector<Complex> roots;
    double r = pow(this->__abs__(), (double)1/n);

    for (unsigned int k = 0; k < n; ++k) {
        double x = (this->__arg__() + 2 * M_PI * k) / n;
        double cosx = cos(x);
        double sinx = sin(x);

        roots.push_back(Complex(r * cosx, r * sinx));
    }

    return roots;
}

Complex Complex::__conjugate__() const {
    return Complex(this->real, -this->imag);
}

double Complex::__abs__() const {
    return sqrt(pow(this->real, 2) + pow(this->imag, 2));
}

/* Operators overloading */

Complex Complex::operator+(const Complex number) const {
    return this->__add__(number);
}

Complex Complex::operator-() const {
    return this->__neg__();
}

Complex Complex::operator-(const Complex number) const {
    return this->__sub__(number);
}

bool Complex::operator==(const Complex number) const {
    return this->__eq__(number);
}

Complex Complex::operator*(const Complex number) const {
    return this->__mul__(number);
}

Complex Complex::operator/(const Complex number) const {
    return this->__div__(number);
}

std::ostream& operator<<(std::ostream& cout_, const Complex& complexNumber) {
    if (complexNumber.get_real()) {
        cout_ << complexNumber.get_real();
    }

    if (complexNumber.get_imag()) {
        if (complexNumber.get_imag() > 0 && complexNumber.get_real() != 0) {
            cout_ << "+";
        }

        cout_ << complexNumber.get_imag() << "i";
    } else if (!complexNumber.get_real()) {
        cout_ << "0";
    }

    return cout_;
}

double abs(const Complex number) {
    return number.__abs__();
}

double arg(const Complex number) {
    return number.__arg__();
}
