/**
 * Class definition for the class MathVector.
 *
 * Dale Shpak
 * Nov. 15, 2009
 * Oct. 30, 2011
 */
#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <iostream>
#include "MathVectorException.h"

class MathVector {
private:
    double *x;
    int size;
public:
    /**
     * Construct a MathVector of the requested size
     * Array elements are not initialized
     *
     * @param N size of the MathVector
     */
    MathVector (const int N);

    /**
     * Construct a MathVector from an existing array
     */
    MathVector (const double x[], const int N);

     /**
     * Copy constructor
     */
    MathVector (const MathVector &b);

    /**
     * Destructor returns the array to the heap
     */
    ~MathVector ();

    /**
     * Overload the stream insertion operator so that we
     * can print a MathVector in its entirety.
     */
    friend std::ostream& operator<< (std::ostream& out, MathVector &vec);

    /**
     * Assignment operator makes a copy of the MathVector on the
     * right-hand side.
     *
     * @param rhs The MathVector on the right-hand side of the =
     */
    MathVector& operator= (const MathVector &rhs);

    /**
     * Array subscripting operator
     *
     * @param index The array index
     * @throw If the array index is out-of-bounds
     */
    double& operator[] (const int index) throw (MathVectorException);

    /**
     * Arithmetic operators operate element-by-element and check for valid sizes */
    const MathVector operator+(const MathVector &b) const throw (MathVectorException);
    const MathVector operator-(const MathVector &b) const throw (MathVectorException);
    const MathVector operator*(const MathVector &b) const throw (MathVectorException); // Hadamard product
    // Notes for COMP 139e:
    // These functions will throw an exception if the sizes are incorrect.
    // They return a const object and
    // they are const functions (they don't modify the object that invokes the function).
    /* You will notice that these operators return a const instance, not a const reference.
     * This is so that people can't write strange statements like this:
     *
     *   MyClass a, b, c;
     *   ...
     *   (a + b) = c;   // Wuh...?
     * This statement would basically do nothing, but if the + operator returns
     * a non-const value, it will compile!
     * So, we want to return a const instance, so that such madness will not
     * even be allowed to compile.
     * http://www.cs.caltech.edu/courses/cs11/material/cpp/donnie/cpp-ops.html
     */
};

#endif
