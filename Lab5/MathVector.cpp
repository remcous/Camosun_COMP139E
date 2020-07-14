/**
 * Some of the functions for the class MathVector.
 * You get to write the others!
 *
 * Dale Shpak
 * Nov. 15, 2009
 */

#include "MathVector.h"

MathVector::MathVector(const int N) : size(N) {
    x = new double[N];
}

MathVector::MathVector(const double x[], const int N){
    size = N;
    this->x = new double[N];
    for(int i=0; i<N; i++){
        this->x[i] = x[i];
    }
}

MathVector::MathVector (const MathVector &b) : size(b.size) {
    x = new double[b.size];
    for (int i=0; i < size; i++) {
        x[i] = b.x[i];
    }
}

MathVector::~MathVector() {
    delete[] x;
}

MathVector& MathVector::operator= (const MathVector &rhs) {
    // Check for self-assignment since we have the array x attached to this object
    if (this == &rhs) {
        return *this;
    }

    // Check if old array is the wrong size
    if (size != rhs.size) {
        delete[] x;
        size = rhs.size;
        x = new double[size];
    }

    // Copy the data
    for (int i=0; i < size; i++) {
        x[i] = rhs.x[i];
    }

    return *this;
}

std::ostream& operator<< (std::ostream &out, MathVector &vec) {
    for (int i=0; i < vec.size; i++) {
        out << vec.x[i] << ' ';
    }

    return out;
}

double& MathVector::operator[] (const int index) throw (MathVectorException){
    if(index >= this->size || index < 0){
        throw MathVectorException("Index out of bounds");
    }
    return this->x[index];
}

const MathVector MathVector::operator+(const MathVector &b) const throw (MathVectorException){
    if(this->size != b.size){
        throw MathVectorException("Cannot add vectors of different sizes");
    }

    double result[this->size];
    
    for(int i=0; i<this->size; i++){
        result[i] = this->x[i] + b.x[i];
    }
    
    return MathVector(result, this->size);
}

const MathVector MathVector::operator-(const MathVector &b) const throw (MathVectorException){
    if(this->size != b.size){
        throw MathVectorException("Cannot subtract vectors of different sizes");
    }

    double result[this->size];
    
    for(int i=0; i<this->size; i++){
        result[i] = this->x[i] - b.x[i];
    }
    
    return MathVector(result, this->size);
}

const MathVector MathVector::operator*(const MathVector &b) const throw (MathVectorException){
    if(this->size != b.size){
        throw MathVectorException("Cannot calculate hadamard product for vectors of different sizes");
    }

    double result[this->size];
    
    for(int i=0; i<this->size; i++){
        result[i] = this->x[i] * b.x[i];
    }
    
    return MathVector(result, this->size);
}