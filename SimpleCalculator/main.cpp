#include <iostream>
#include <bits/stdc++.h>
#include "simpleCalculator.h"

class Calculator {
public:
    Calculator() {
        op_ = 'a';
    }

    void parseInt(char character) {
        switch (character) {
            case '1':
                int_vector_.push_back(1);
                break;
            case '2':
                int_vector_.push_back(2);
                break;
            case '3':
                int_vector_.push_back(3);
                break;
            case '4':
                int_vector_.push_back(4);
                break;
            case '5':
                int_vector_.push_back(5);
                break;
            case '6':
                int_vector_.push_back(6);
                break;
            case '7':
                int_vector_.push_back(7);
                break;
            case '8':
                int_vector_.push_back(8);
                break;
            case '9':
                int_vector_.push_back(9);
                break;
            default:
                std::cout << "Error: unrecognized input!";
                break;
        }
    }

    int evalExpression (char op) {
        switch (op) {
            case '+':
                return int_vector_[0] + int_vector_[1];
            case '-':
                return int_vector_[0] - int_vector_[1];
            case '*':
                return int_vector_[0] * int_vector_[1];
            case '/':
                return std::trunc(int_vector_[0] / int_vector_[1]);
        }
    }

    int calculate(std::string string) {
        for (auto &character : string) {
            if (character == '+' || character == '-' || character == '*' || character == '/') {
                op_ = character;
            }
            else {
                parseInt(character);
            }
        }
        return evalExpression(op_);
    }

private:
    std::vector<int> int_vector_;
    char op_{};
};

int main() {
    //my own shitty calculator
//    std::string test_string = "9/2";
//    Calculator calc;
//    std::cout<<calc.calculate(test_string)<<std::endl;

    //the good stuff
    SimpleCalculator<int> simpleCalc;
    int result2 = simpleCalc.eval("12*2+2/2");
    std::cout<<"RESULT: "<<result2<<std::endl;


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