/*
 * A Square that is derived from Rectangle
 *
 * File:   Square.h
 * Author: Remi Coussement
 *
 * Created on October 24, 2017
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"
#include <iostream>

class Square : public Rectangle {
private:

protected:
    void printMe(std::ostream& os) const;
public:
    /**
     * This constructor passes the x,y location to the base class constructor
     * in Shape and also initializes the Rectangle's size.
     *
     * We choose to make this an inline function.
     *
     * @param l Length
     * @param xLoc Initial x coordinate
     * @param yLoc Initial y coordinate
     */
    inline Square(double l, int x, int y)
        : Rectangle(l, l, x, y){
    }


    /**
     * The Rectangle "draws" itself at its current location
     */
    void draw() const;
};


#endif  /* RECTANGLE_H */

