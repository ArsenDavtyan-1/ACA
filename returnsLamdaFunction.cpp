#include <iostream>


int main()
{
    auto mult = [](int m) {

        return [=](int n)
            {
                return m * n;
            };
    };


    int result = mult(4)(5);

    std::cout << "result = " << result << std::endl;
    return 0;
}
