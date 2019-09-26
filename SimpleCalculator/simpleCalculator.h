#ifndef SIMPLECALCULATOR_SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_SIMPLECALCULATOR_H

#include <stdexcept>
#include <string>
#include <sstream>
#include <stack>
#include <cstddef>
#include <cctype>
#include <iostream>

template <typename T>
class SimpleCalculator
{
public:
    T eval(const std::string& expr)
    {
        T result = 0;
        index_ = 0;
        expr_ = expr;
        result = parseExpr();
        return result;
    }

private:
    enum
    {
        OPERATOR_NULL,
        OPERATOR_ADDITION,       /// +
        OPERATOR_SUBTRACTION,    /// -
        OPERATOR_MULTIPLICATION, /// *
        OPERATOR_DIVISION,       /// /
    };

    struct Operator
    {
        /// Operator, one of the OPERATOR_* enum definitions
        int op;
        int precedence;
        /// 'L' = left or 'R' = right
        int associativity;
        Operator(int opr, int prec, int assoc) :
                op(opr),
                precedence(prec),
                associativity(assoc)
        { }
    };

    struct OperatorValue
    {
        Operator op;
        T value;
        OperatorValue(const Operator& opr, T val) :
                op(opr),
                value(val)
        { }
        int getPrecedence() const
        {
            return op.precedence;
        }
        bool isNull() const
        {
            return op.op == OPERATOR_NULL;
        }
    };

    /// Expression string
    std::string expr_;
    /// Current expression index, incremented whilst parsing
    std::size_t index_{};
    /// The current operator and its left value
    /// are pushed onto the stack if the operator on
    /// top of the stack has lower precedence.
    std::stack<OperatorValue> stack_;

    T calculate(T v1, T v2, const Operator& op) const
    {
        switch (op.op)
        {
            case OPERATOR_ADDITION:       return v1 + v2;
            case OPERATOR_SUBTRACTION:    return v1 - v2;
            case OPERATOR_MULTIPLICATION: return v1 * v2;
            case OPERATOR_DIVISION:       return v1 / v2;
            default:                      return 0;
        }
    }

    bool isEnd() const
    {
        return index_ >= expr_.size();
    }

    char getCharacter() const
    {
        if (!isEnd())
            return expr_[index_];
        return 0;
    }

    void eatSpaces()
    {
        while (std::isspace(getCharacter()) != 0)
            index_++;
    }

    Operator parseOp()
    {
        eatSpaces();
        switch (getCharacter())
        {
            case '+': index_++;     return Operator(OPERATOR_ADDITION,       10, 'L');
            case '-': index_++;     return Operator(OPERATOR_SUBTRACTION,    10, 'L');
            case '/': index_++;     return Operator(OPERATOR_DIVISION,       20, 'L');
            case '*': index_++;     return Operator(OPERATOR_MULTIPLICATION, 20, 'L');
            default :               return Operator(OPERATOR_NULL,            0, 'L');
        }
    }

    static T toInteger(char c)
    {
        if (c >= '0' && c <= '9') return c -'0';
//        std::cout<<"returning no digit"<<std::endl;
        T noDigit = 0xf + 1;
        return noDigit;
    }

    T getInteger() const
    {
        return toInteger(getCharacter());
    }

    T parseDecimal()
    {
        T value = 0;
        for (T d; (d = getInteger()) <= 9; index_++) {
//            std::cout << "d = " << d << std::endl;
            value = value * 10 + d;
//            std::cout << "value = " << value << std::endl;
        }
        return value;
    }

    T parseValue()
    {
        T val = 0;
        eatSpaces();
        switch (getCharacter())
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                val = parseDecimal();
                break;
            case '(': index_++;
                val = parseExpr();
                eatSpaces();
                index_++; break;
            case '+': index_++; val =  parseValue(); break;
            case '-': index_++; val =  parseValue() * static_cast<T>(-1);
                break;
            default :
                std::cout<<"Syntax error: value expected at end of expression"<<std::endl;
        }
        return val;
    }

    T parseExpr()
    {
        stack_.push(OperatorValue(Operator(OPERATOR_NULL, 0, 'L'), 0));
        // first parse value on the left
        T value = parseValue();

        while (!stack_.empty())
        {
//            std::cout << "index_ = "<<index_<<std::endl;
//            std::cout << stack_.top().value<<std::endl;
            // parse an operator (+, -, *, ...)
            Operator op(parseOp());
            while (op.precedence  < stack_.top().getPrecedence() || (
                    op.precedence == stack_.top().getPrecedence() &&
                    op.associativity == 'L'))
            {
                // end reached
                if (stack_.top().isNull())
                {
                    stack_.pop();
                    return value;
                }
                // do the calculation ("reduce"), producing a new value
                value = calculate(stack_.top().value, value, stack_.top().op);
                std::cout<<"value = "<<value<<std::endl;
                stack_.pop();
            }

            // store on stack_ and continue parsing ("shift")
            stack_.push(OperatorValue(op, value));
            // parse value on the right
            value = parseValue();
        }
        return 0;
    }

};

//template <typename T>
//inline T eval(const std::string& expression)
//{
//    SimpleCalculator<T> parser;
//    return parser.eval(expression);
//}
//
//inline int eval(const std::string& expression)
//{
//    return eval<int>(expression);
//}


#endif //SIMPLECALCULATOR_SIMPLECALCULATOR_H
