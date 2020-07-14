/*
 * A main() to demonstrate inheritance, polymorphism, virtual functions,
 * and an abstract class.
 * Uses classes: ShapeStack, Shape, Rectangle, Square, and Circle.
 * 
 * File:   main.cpp
 * Author: Remi Coussement
 *
 * Created on October 24, 2017
 */
#include <iostream>
#include <cstdlib>
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "ShapeStack.h"

int main(int argc, char* argv[]) {
    ShapeStack shapes;
    Shape *sp;
    
    try{
        std::cout << "Pushing Circle(20.5, 4, 10) to the Stack.\n";
        shapes.push(new Circle(20.5, 4, 10));
        std::cout << *shapes.top() << std::endl;
        std::cout << "Pushing Rectangle(10, 20.7, 8, 8) to the Stack.\n";
        shapes.push(new Rectangle(10, 20.7, 8, 8));
        std::cout << *shapes.top() << std::endl;
        std::cout << "Pushing Square(11, 10, 5) to the Stack.\n";
        shapes.push(new Square(11, 10, 5));
        std::cout << *shapes.top() << std::endl;
        std::cout << shapes.size() << " elements in the stack" << std::endl;

        std::cout << "\nMoving top shape on stack to (17, 4)\n";
        shapes.top()->moveTo(17, 4);

        std::cout<< "\nPopping all elements off the stack.\n";
        while(!shapes.isEmpty()){
            sp = shapes.pop();
            sp->draw();
            delete sp;
        }

        std::cout<<"Popping complete.\n";

        std::cout << "\nPopping an empty stack:\n";
        sp = shapes.pop();
    }
    catch(StackException msg){
        std::cerr << msg.getMessage() << std::endl;
    }

    return EXIT_SUCCESS;
}

