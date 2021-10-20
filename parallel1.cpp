#include <iostream>

int main(void)
{
    #pragma omp parallel
    {
        std::cout << "Hello" << std::endl;
    }
    return 0;
}