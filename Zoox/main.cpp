#include "calculator.hpp"
#include <stdint.h>
#include <iostream>

int main()
{
    try
    {
        int result = calculator::eval("(0 + ~(255 & 1000)*3) / -2");
        int result2 = calculator::eval(" 3+5 / 2 ");

        std::cout << result << std::endl;
        std::cout << result2 << std::endl;

        // 64-bit arithmetic
        int64_t r64 = calculator::eval<int64_t>("2**60");
        std::cout << r64 << std::endl;
    }
    catch (calculator::error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}