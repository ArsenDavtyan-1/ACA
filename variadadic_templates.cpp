#include <iostream>

void print() {
    std::cout << std::endl;
}

template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...); 
}

int main()
{
    print(1, 2, 3);
    print("sdfsdf", 5665, 0.2, 'd', "adsf");
}