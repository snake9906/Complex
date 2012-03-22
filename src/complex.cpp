/**
  Copyright [year] <Copyright Owner>
  */

#include <vector>

#include "include/complex.h"


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

Complex& Complex::__copy__(const Complex& number) {
    this->real = number.real;
    this->imag = number.imag;

    return *this;
}

void Complex::set_real(double real) {
    this->real = real;
}
void Complex::set_imag(double imag) {
    this->imag = imag;
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

bool Complex::__eq__(const Complex& number) const {
    return this->real == number.real && this->imag == number.imag;
}

Complex Complex::__neg__() const {
    return Complex(-this->real, -this->imag);
}

Complex Complex::__conjugate__() const {
    return Complex(this->real, -this->imag);
}

double Complex::__abs__() const {
    return sqrt(pow(this->real, 2) + pow(this->imag, 2));
}

double Complex::__arg__() const {
    double phi = atan(this->imag / this->real);

    if (this->real < 0) {
        this->imag >= 0 ? phi += M_PI : phi -= M_PI;
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

Complex Complex::__add__(const Complex& number) const {
    return Complex(this->real + number.real, this->imag + number.imag);
}

Complex Complex::__sub__(const Complex& number) const {
    return this->__add__(number.__neg__());
}

Complex Complex::__mul__(const Complex& number) const {
    return Complex(this->real * number.real - this->imag * number.imag,
                   this->imag * number.real + this->real * number.imag);
}

Complex Complex::__div__(const Complex& number) const {
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

void Complex::__radd__(const Complex& number) {
    this->real += number.real;
    this->imag += number.imag;
}

void Complex::__rsub__(const Complex& number) {
    this->real -= number.real;
    this->imag -= number.imag;
}

void Complex::__rmul__(const Complex& number) {
    Complex newComplexNumber = this->__mul__(number);
    this->real = newComplexNumber.real;
    this->imag = newComplexNumber.imag;
}

void Complex::__rdiv__(const Complex& number) {
    Complex newComplexNumber = this->__div__(number);
    this->real = newComplexNumber.real;
    this->imag = newComplexNumber.imag;
}

Complex Complex::__pow__(int n) {
    double rn = pow(this->__abs__(), n);
    double x = n * this->__arg__();

    return Complex(rn * cos(x), rn * sin(x));
}

std::vector<Complex> Complex::__roots__(const unsigned int n) {
    std::vector<Complex> roots;

    double rn = pow(this->__abs__(), 1.0/n);

    for (unsigned int k = 0; k < n; ++k) {
        double x = (this->__arg__() + 2 * M_PI * k) / n;
        roots.push_back(Complex(rn * cos(x), rn * sin(x)));
    }

    return roots;
}

/* Operators overloading */

Complex Complex::operator=(const Complex& number) {
    return this->__copy__(number);
}

bool Complex::operator==(const Complex& number) const {
    return this->__eq__(number);
}

Complex Complex::operator+(const Complex& number) const {
    return this->__add__(number);
}

Complex Complex::operator-() const {
    return this->__neg__();
}

Complex Complex::operator-(const Complex& number) const {
    return this->__sub__(number);
}

Complex Complex::operator*(const Complex& number) const {
    return this->__mul__(number);
}

Complex Complex::operator/(const Complex& number) const {
    return this->__div__(number);
}

void Complex::operator+=(const Complex& number) {
    this->__radd__(number);
}

void Complex::operator-=(const Complex& number) {
    this->__rsub__(number);
}

void Complex::operator*=(const Complex& number) {
    this->__rmul__(number);
}

void Complex::operator/=(const Complex& number) {
    this->__rdiv__(number);
}

/* Friend functions */

double abs(const Complex& number) {
    return number.__abs__();
}

double arg(const Complex& number) {
    return number.__arg__();
}

Complex pow(Complex number, unsigned int n) {
    return number.__pow__(n);
}

std::ostream& operator<<(std::ostream& cout_, const Complex& complexNumber) {
    if (complexNumber.real) {
        cout_ << complexNumber.real;
    }

    if (complexNumber.imag) {
        if (complexNumber.imag > 0 && complexNumber.real != 0) {
            cout_ << "+";
        }

        cout_ << complexNumber.imag << "i";
    } else if (!complexNumber.real) {
        cout_ << "0";
    }

    return cout_;
}

/* Comparison by absolute value */

bool Complex::__gt__(const Complex& number) const {
    return this->__abs__() > number.__abs__();
}

bool Complex::__ge__(const Complex& number) const {
     return this->__abs__() >= number.__abs__();
}

bool Complex::__lt__(const Complex& number) const {
    return this->__abs__() < number.__abs__();
}

bool Complex::__le__(const Complex& number) const {
    return this->__abs__() <= number.__abs__();
}

bool Complex::operator>(const Complex& number) const {
    return this->__gt__(number);
}

bool Complex::operator<(const Complex& number) const {
    return this->__lt__(number);
}

bool Complex::operator>=(const Complex& number) const {
    return this->__ge__(number);
}

bool Complex::operator<=(const Complex& number) const {
    return this->__le__(number);
}
