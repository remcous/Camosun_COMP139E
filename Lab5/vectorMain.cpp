/**
 * Exercising the class MathVector.
 *
 * Dale Shpak
 * Nov. 15, 2009
 */
#include <cstdlib>
#include <iostream>
#include "MathVector.h"

using namespace std;

int main(int argc, char *argv[]) {
    double q[] = {1.0, 2.0, 3.0};
    MathVector b(3);     // First constructor
    MathVector a(q, 3);  // Second constructor

    try {
        q[0] = 7.1;
        if (a[0] == q[0]) {
            cerr << "Error:  Your constructor must make a copy of the data" << endl;
        }
      
        b[0] = -5.0;
        b[1] = -7.5;
        b[2] = a[1];

        cout << "Vector a: " << a << endl;
        cout << "Vector b: " << b << endl;
        MathVector d(a);  // Try the copy constructor
        cout << "Vector d: " << b << endl;

        MathVector c = a + b;  // Addition and assignment
        cout << "Addition: " << c << endl;

        c = a - b;
        cout << "Subtraction: " << c << endl;

        c = a * b;
        cout << "Hadamard product: " << c << endl;
    }    catch (MathVectorException ex) {
        cerr << "Caught exception: " << ex.getError() << endl;
        cerr << "We should not see this message since nothing in " << endl
                << "this code block should throw an exception." << endl;
    }

    try {
        b[3] = a[2]; // Should throw an exception
        cerr << "If we see this message, the bad array index exception is NOT working" << endl;
    }    catch (MathVectorException ex) {
        cerr << "Caught exception: " << ex.getError() << endl;
    }

    try {
        b[-4] = a[2]; // Should throw an exception
        cerr << "If we see this message, the bad array index exception is NOT working" << endl;
    }    catch (MathVectorException ex) {
        cerr << "Caught exception: " << ex.getError() << endl;
    }

    try {
        MathVector d(5);
        MathVector f = a + d; // Should throw an exception
        f[2] = 5.5;
    }    catch (MathVectorException ex) {
        cerr << "Caught exception: " << ex.getError() << endl;
    }

    return EXIT_SUCCESS;
}
