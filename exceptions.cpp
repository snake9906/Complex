#include "exceptions.h"


DivideByZeroException::DivideByZeroException() :
    std::runtime_error("attempted to divide by zero") {
}

IndeterminateValueException::IndeterminateValueException() :
    std::runtime_error("indeterminate value") {
}
