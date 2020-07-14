/*
 * Main to utilize Shape and its derived classes Rectangle and
 * Circle and the STL vector to store their objects
 * 
 * File:   Lab7.cpp
 * Author: Remi Coussement
 *
 * Created on November 5, 2017
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main(){
    try{
        vector<Shape*> shapes;

        cout << "Creating shapes:" << endl;
        shapes.push_back(new Circle(20.5, 4, 10));
        shapes.push_back(new Rectangle(10, 20.7, 8, 8));
        vector<Shape*>::iterator iter=shapes.begin();
        shapes.insert(iter, 2, new Circle(11, 10, 5));

        for(iter = shapes.begin(); iter != shapes.end(); iter++){
            (*iter)->draw();
        }

        cout << "\nMaximum number of elements possible: " 
            << shapes.max_size() << endl;

        cout << "\nPopping a shape from the back of the vector:\n";
        cout << "\tSize before: " << shapes.size() << endl;
        cout << "\tCapacity before: " << shapes.capacity() << endl;

        shapes.pop_back();
        cout << "\tSize after: " << shapes.size() << endl;
        cout << "\tCapacity after: " << shapes.capacity() << endl;

        cout << "\nDrawing shape at index 0:\n";
        shapes[0]->draw();

        cout << "\nAccessing index 4 of vector using .at():" << endl;
        shapes.at(4);
    }
    catch(out_of_range& ex){
        cerr << "Out of range: \n\t" << ex.what() << endl;
    }

    return 0;
}