#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>


class DivideByZeroException : public std::runtime_error {
public:
    DivideByZeroException();
};

#endif // DIVIDEBYZEROEXCEPTION_H

class IndeterminateValueException : public std::runtime_error {
public:
    IndeterminateValueException();
};
