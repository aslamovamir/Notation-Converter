#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H
#include "NotationConverterInterface.hpp"
#include "Deque.hpp"
#include<iostream>

//Class of the notation converter
class NotationConverter : public NotationConverterInterface{
    public:
        std::string postfixToInfix(std::string inStr);
        std::string postfixToPrefix(std::string inStr);
        std::string infixToPostfix(std::string inStr);
        std::string infixToPrefix(std::string inStr);
        std::string prefixToInfix(std::string inStr);
        std::string prefixToPostfix(std::string inStr);
        std::string toString(); 
    private:
        Deque dequeOrig; // Main deck that will be used to convert between the notations
        Deque dequeOperands; // Temporary dequeOrig to store dequeOperands when converting between notations
        Deque dequeOperators; // Temporary dequeOrig to store dequeOperators when converting between notations
};

#endif