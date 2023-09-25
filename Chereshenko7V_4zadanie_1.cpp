#include <iostream>

int main()
{
    int A,B,C;
    std::cin >> A >> B >> C;
    if ((A%B == 0) && (B>C)){
        std::cout << A / B + C;             
    }
    else if ((A % B == 0) && (B<C)){
        std::cout << A/B-C;
    }
    else {
        std::cout << (A + B) * C;
    }  
    return 0;
}