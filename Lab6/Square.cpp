/*
 * Implementation of the Square class
 *
 * File:   Square.cpp
 * Author: Remi Coussement
 *
 * Created on October 24, 2017
 */
#include "Square.h"
#include <iostream>

/**
 * The draw() member function
 */
void Square::draw() const {
    std::cout << "Square of size [" << length << "." << length << "] drawn at " << getX() << " " << getY() << std::endl;
}

void Square::printMe(std::ostream& os) const {
    os << "Square of size [" << getLength() << " " << getLength() << "] at " << getX() << " " << getY();
}
