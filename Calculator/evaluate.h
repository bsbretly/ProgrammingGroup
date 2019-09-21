//
// Created by root on 19.09.19.
//

#ifndef CALCULATOR_EVALUATE_H
#define CALCULATOR_EVALUATE_H

#include <stdexcept>
#include <string>
#include <sstream>
#include <stack>
#include <cstddef>
#include <cctype>

template <typename T>
class ExpressionParser
{
public:
    T eval(const std::string& expr) {
        T result = 0;
        result = parseExpr();
        return result;
    }

    //int value of a character
    T eval(char c) {
        std::string expr(1,c);
        return eval(expr);
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

    struct OperatorValue {
        Operator op;
        T value;

        OperatorValue(const Operator &opr, T val) :
                op(opr),
                value(val) {}

        int getPrecedence() const {
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
    std::size_t index_;
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
        }
    }

    bool isEnd() const
    {
        return index_ >= expr_.size();
    }

    /// Returns the character at the current expression index or
    /// 0 if the end of the expression is reached.
    ///
    char getCharacter() const
    {
        if (!isEnd())
            return expr_[index_];
        return 0;
    }

    /// Parse str at the current expression index.
    /// @throw error if parsing fails.
    ///
    void expect(const std::string& str)
    {
        index_ += str.size();
    }

    /// Eat all white space characters at the
    /// current expression index.
    ///
    void eatSpaces()
    {
        while (std::isspace(getCharacter()) != 0)
            index_++;
    }

    /// Parse a binary operator at the current expression index.
    /// @return Operator with precedence and associativity.
    ///
    Operator parseOp()
    {
        eatSpaces();
        switch (getCharacter())
        {
            case '+': index_++;     return Operator(OPERATOR_ADDITION,       10, 'L');
            case '-': index_++;     return Operator(OPERATOR_SUBTRACTION,    10, 'L');
            case '/': index_++;     return Operator(OPERATOR_DIVISION,       20, 'L');
            case '*': index_++;     return Operator(OPERATOR_MULTIPLICATION, 20, 'L');
        }
    }

    static T toInteger(char c)
    {
        return c -'0';
    }

    T getInteger() const
    {
        return toInteger(getCharacter());
    }

    T parseDecimal()
    {
        T value = 0;
        for (T d; (d = getInteger()) <= 9; index_++)
            value = value * 10 + d;
        return value;
    }

    /// Parse an integer value at the current expression index.
    /// The unary `+', `-' and `~' operators and opening
    /// parentheses `(' cause recursion.
    ///
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
            case '(':
                index_++;
                val = parseExpr();
                eatSpaces();
                index_++; break;
            case '+': index_++; val =  parseValue(); break;
            case '-': index_++; val =  parseValue() * static_cast<T>(-1);
                break;
        }
        return val;
    }

    /// Parse all operations of the current parenthesis
    /// level and the levels above, when done
    /// return the result (value).
    ///
    T parseExpr()
    {
        stack_.push(OperatorValue(Operator(OPERATOR_NULL, 0, 'L'), 0));
        // first parse value on the left
        T value = parseValue();

        while (!stack_.empty())
        {
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

template <typename T>
inline T eval(const std::string& expression)
{
    ExpressionParser<T> parser;
    return parser.eval(expression);
}

template <typename T>
inline T eval(char c)
{
    ExpressionParser<T> parser;
    return parser.eval(c);
}

inline int eval(const std::string& expression)
{
    return eval<int>(expression);
}

inline int eval(char c)
{
    return eval<int>(c);
}

#endif //CALCULATOR_EVALUATE_H
