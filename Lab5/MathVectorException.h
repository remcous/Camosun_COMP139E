#ifndef MATH_VECTOR_EXCEPTION_H
#define MATH_VECTOR_EXCEPTION_H

#include <string>

class MathVectorException {
private:
    std::string error;
public:
    inline MathVectorException (const char *message) {
        error = message;
    }

    inline const std::string& getError(void) const {
        return error;
    }
};

#endif