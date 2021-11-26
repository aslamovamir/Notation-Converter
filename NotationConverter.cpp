#include "NotationConverter.hpp"

// To convert a string in postfix notation to infix notation
std::string NotationConverter::postfixToInfix(std::string inStr)    {
    
    if(!isalpha(inStr[0])) {
        throw inStr;
    }

    for(unsigned int i=0; i<inStr.size(); ++i){
        if(inStr[i] != ' '){ 
        // We move the deque Operators to the temporary dequeOperators deque
        if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
             dequeOperators.insertBack(inStr[i]);
        }
            // We move operands to the dequeOpearands deque
        else { 
            dequeOperands.insertBack(inStr[i]);
        }
        }
    }
    // We check if the expression is valid
    // if not, we throw an error
    if(dequeOperators.size() != dequeOperands.size()-1) {
        throw inStr;
    }
    dequeOrig.insertBack('(');
    int count = dequeOperators.size();
    // We ensure if we need to insert more than one paranthesis
    for(int i=1; i<count-1; ++i) dequeOrig.insertBack('(');
    // We now move elements from the operands deque and the operators deque and move them to the final converted deque
    while(!dequeOperands.isEmpty()){
        dequeOrig.insertBack(dequeOperands.front());
        dequeOperands.removeFront();
        // We will keep pulling elements left
        if(!dequeOperators.isEmpty()){
            if(dequeOperators.size() == 2){
                dequeOrig.insertBack(')');
                dequeOrig.insertBack(dequeOperators.back());
                dequeOperators.removeBack();
                dequeOrig.insertBack('(');
            }
            else {
                dequeOrig.insertBack(dequeOperators.front());
                dequeOperators.removeFront();
            }
        }
    }
    dequeOrig.insertBack(')');

    // We insert the necessary parantheses to make the expression complete
    for(int i=1; i<count-1; ++i) {
        dequeOrig.insertBack(')');
    }
    // Now we can return the elements from the dequeOriginal as a string
    return toString();
}

// To convert a postfix notation to prefix notation
std::string NotationConverter::postfixToPrefix(std::string inStr)   {
return infixToPrefix(postfixToInfix(inStr));
}

// To convert an infix notation to postfix notation
std::string NotationConverter::infixToPostfix(std::string inStr)    {
// We check if the expression is valid
    if(inStr[0] != '('){ 
        throw inStr;
    }

    for(unsigned int i=0; i<inStr.size(); ++i)  {
        // We remove parenthesis from the infix notation
        while(inStr[i] != ')' && inStr[i] != *inStr.end()){
            if(inStr[i] != ' '){
            // Store dequeOperators in the temporary dequeOrig
            if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
            dequeOperators.insertBack(inStr[i]);
            }

        // We store dequeOperands in the main dequeOrig
        else if(inStr[i] != '(') {
        dequeOrig.insertBack(inStr[i]);
        }
        }
        i++;
    }
    
    int count = dequeOperators.size();
    for(int i = 0; i < count; i++){
        if(dequeOperators.size() == 2){
            dequeOrig.insertBack(dequeOperators.back());
            dequeOperators.removeBack();
        } else {
            dequeOrig.insertBack(dequeOperators.front());
            dequeOperators.removeFront();
        }
        }
    }
 //now we return the result as a string
    return toString();
}

// To convert an infix notation to prefix
std::string NotationConverter::infixToPrefix(std::string inStr){
// We check if the expression is valid
    if(inStr[0] != '('){ 
        throw inStr;
    }

    for(unsigned int i=0; i<inStr.size(); ++i){
    // We remove parenthesis from the infix notation
        while(inStr[i] != ')' && inStr[i] != *inStr.end()){
            if(inStr[i] != ' '){
                if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
                if(inStr[i-2] == ')'){
                    dequeOrig.insertFront(inStr[i]);
                }
                // Else we insert to the back of the main dequeOrig
                else {
                dequeOrig.insertBack(inStr[i]);
            }
            }
            // We insert the dequeOperands into the temporary dequeOperands dequeOrig
            else if(inStr[i] != '(') dequeOperands.insertBack(inStr[i]);
        }
        i++;
    }

    int count = dequeOperands.size();
    for(int i=0; i<count; ++i){
        dequeOrig.insertBack(dequeOperands.front());
        dequeOperands.removeFront();
    }
}

// W return the result as a string
return toString();
}

// To convert from prefix notation to infix
std::string NotationConverter::prefixToInfix(std::string inStr){
// We check if the expression is valid
    if(inStr[0] != '+' && inStr[0] != '-' && inStr[0] != '*' && inStr[0] != '/') { 
        throw inStr;
    }

    // We check if parenthesis are needed and store count to make sure there is an even amount
    bool needParenthesis = false;
    int parantheses_num= 0;
    for(unsigned int i=0; i<inStr.size(); ++i){
        if(inStr[i] != ' '){
        // Insert dequeOperators into dequeOperators dequeOrig
        if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
            dequeOperators.insertBack(inStr[i]);
            dequeOrig.insertBack('(');
            parantheses_num++;
            needParenthesis = false; // No operand found yet
        }
        else {
            dequeOrig.insertBack(inStr[i]);
            // We insert a parenthesis after an operator in between two dequeOperands is inserted
            if(needParenthesis == true){
            dequeOrig.insertBack(')');
            parantheses_num--;
        }
    // We insert the operator from the dequeOperands dequeOrig into the main dequeOrig
    if(dequeOperators.isEmpty() == false){
        dequeOrig.insertBack(dequeOperators.back());
        dequeOperators.removeBack();
        needParenthesis = true; // Parenthesis is now needed in the next iteration of the loop
    }   
    }
    }
}


// W check the number of opening and closing parentheses
if(parantheses_num != 0){
    while(parantheses_num != 0){
        dequeOrig.insertBack(')');
        parantheses_num--;
        }
}

// We return the result as a string
return toString();
}

// To convert from prefix to postfix notation
std::string NotationConverter::prefixToPostfix(std::string inStr){
    return infixToPostfix(prefixToInfix(inStr));
}

std::string NotationConverter::toString(){
std::string outStr;
// We check if the dequeOrig is empty
if(dequeOrig.isEmpty()) {
    return outStr;
}

int size = dequeOrig.size();
// We flip the parantheses to make it valid expression
for(unsigned int i=0; i<size; ++i){
    if(dequeOrig.front() == ')') outStr.pop_back();
    outStr += dequeOrig.front();
    if(dequeOrig.front() != '(') outStr += ' ';
    dequeOrig.removeFront();
}
//We remove reduntant spaces
outStr.pop_back();
// We return the result as a string
return outStr;
}