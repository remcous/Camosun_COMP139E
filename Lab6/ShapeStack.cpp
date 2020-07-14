/*
 * Implementation of the ShapeStack class
 *
 * File:   ShapeStack.cpp
 * Author: Remi Coussement
 *
 * Created on October 24, 2017
 */
#include "ShapeStack.h"

/**
 * Push a Shape onto the stack
 *
 * @param shape Pointer to the Shape to be stored
 */
void ShapeStack::push (Shape *shape){
    StackNode *new_node = new StackNode;
    new_node->next = this->topItem;
    new_node->theShape = shape;
    this->topItem = new_node;
    count++;
}

/**
 * Remove a Shape from the stack
 *
 * @throw A StackException if the stack is empty
 * @return A pointer to the Shape
 */
Shape* ShapeStack::pop(void) throw (StackException){
    if(this->isEmpty()){
        throw StackException("Empty Stack cannot be popped");
    }
    StackNode *node = this->topItem;
    Shape *shape = node->theShape;
    this->topItem = this->topItem->next;
    delete node;
    count--;
    return shape;
}

/**
 * Peek at the Shape at the top of the stack
 *
 * @throw A StackException if the stack is empty
 * @return
 */
Shape* ShapeStack::top(void) throw (StackException){
    if(this->isEmpty()){
        throw StackException("Empty Stack has no top element");
    }
    return topItem->theShape;
}