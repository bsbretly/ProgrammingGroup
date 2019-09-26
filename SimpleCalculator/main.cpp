#include <iostream>
#include <bits/stdc++.h>
#include "simpleCalculator.h"

class Calculator {
public:
    explicit Calculator(std::string& string) : string_(string)
    {
        index_ = 0;
    }

    enum Operator
    {
        OPERATOR_NULL,
        OPERATOR_ADDITION,       /// +
        OPERATOR_SUBTRACTION,    /// -
        OPERATOR_MULTIPLICATION, /// *
        OPERATOR_DIVISION,       /// /
    };

    struct OperatorValue
    {
        Operator op;
        int value;
        OperatorValue(const Operator& opr, int val) :
                op(opr),
                value(val)
        { }
        bool isNull() const {
            return op == OPERATOR_NULL;
        }
    };

    ///*******Helper functions*******///
    /// check if we are at the end of the input string
    bool isEnd() const {
        return index_ >= string_.size();
    }

    /// return character at current index from input string
    char getCharacter() const {
        if (!isEnd())
            return string_[index_];
        return 0;
    }
    /// converts a character to integer
    static int toInteger(char c) {
        if (c >= '0' && c <= '9') return c -'0';
        int noDigit = 0xf + 1;
        return noDigit;
    }
    /// gets integer at current index
    int getInteger() const {
        return toInteger(getCharacter());
    }
    /// parses integers > 9 (ie "10" will return as 10 and not 1, 0)
    int parseInteger() {
        int value = 0;
        for (int d; (d = getInteger()) <= 9; index_++) {
            value = value * 10 + d;
        }
        return value;
    }
    /// increment index for white spaces
    void eatSpaces() {
        while (std::isspace(getCharacter()) != 0)
            index_++;
    }

    /// parse the operator
    Operator parseOp() {
        eatSpaces();
        switch (getCharacter()) {
            case '+': index_++;     return Operator(OPERATOR_ADDITION);
            case '-': index_++;     return Operator(OPERATOR_SUBTRACTION);
            case '/': index_++;     return Operator(OPERATOR_DIVISION);
            case '*': index_++;     return Operator(OPERATOR_MULTIPLICATION);
            default :               return Operator(OPERATOR_NULL);
        }
    }

    /// parse the integer values
    int parseValue()
    {
        int val = 0;
        eatSpaces();
        switch (getCharacter()) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                val = parseInteger();
                break;
            case '(': index_++;
                val = parseExpression();
                eatSpaces();
                index_++; break;
            case '+':
                index_++;
                val =  parseValue();
                break;
            case '-':
                index_++;
                val =  parseValue() * -1;
                break;
            default :
                std::cout<<"Syntax error: value expected at end of expression"<<std::endl;
        }
        return val;
    }

    static int calculate(int v1, int v2, Operator op) {
        switch (op) {
            case OPERATOR_ADDITION:       return v1 + v2;
            case OPERATOR_SUBTRACTION:    return v1 - v2;
            case OPERATOR_MULTIPLICATION: return v1 * v2;
            case OPERATOR_DIVISION:       return v1 / v2;
            default:                      return 0;
        }
    }

    ///*******Heavy lifting done here*******///

    /// evaluate the input expression (ie string)
    int parseExpression () {
        stack_.push(OperatorValue(OPERATOR_NULL,0));
        int value = parseValue();
        while (!stack_.empty()) {
//            std::cout<<"op = "<<op<<std::endl;
//            std::cout<<"stack_.top().value = "<<stack_.top().value<<std::endl;
//            std::cout<<"stack_.top().op = "<<stack_.top().op<<std::endl;
            Operator op = parseOp();
            stack_.push(OperatorValue(op,value));

            if (stack_.top().isNull()) {
                stack_.pop();
                return value;
            }

            std::cout<<"stack_.top().value = "<<stack_.top().value<<'\n'
                     <<"value = "<<value<<'\n'
                     <<"stack_.top().op = "<<stack_.top().op<<std::endl;
            value = parseValue();
            value = calculate(stack_.top().value, value, stack_.top().op);
            std::cout<<"value = "<<value<<std::endl;
            stack_.pop();
            // store on stack_ and continue parsing ("shift")
            stack_.push(OperatorValue(op, value));
            // parse value on the right
//            value = parseValue();
        }
        return 0;
    }

private:
    int index_;
    std::string string_;
    std::stack<OperatorValue> stack_;
};

int main() {
    //my own shitty calculator
    std::string expression = "10/2";
    Calculator calc(expression);
    std::cout<<"RESULT1: "<<calc.parseExpression()<<std::endl;

    //the good stuff
//    SimpleCalculator<int> simpleCalc;
//    int result2 = simpleCalc.eval("9*2");
//    std::cout<<"RESULT2: "<<result2<<std::endl;


//int L_int = 'L';
//int R_int = 'R';
//std::cout<<"L_int = "<<L_int<<std::endl;
//std::cout<<"R_int = "<<R_int<<std::endl;

//char c = '8';
//int test = c - '0';
//std::cout<<"test = "<<test<<std::endl;

//char noDigit = 0xf + 1;
//std::cout<<"noDigit = "<<noDigit<<std::endl;
}