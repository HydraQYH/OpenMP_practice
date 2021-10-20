#include <iostream>
#include <omp.h>

int main(void)
{
    int k = 100;

    omp_set_num_threads(4);
    #pragma omp parallel private(k)
    {
        std::cout << k << std::endl;
    }

    std::cout << "Main Thread k: " << k << std::endl;
    #pragma omp parallel firstprivate(k)
    {
        std::cout << k << std::endl;
    }

    return 0;
}
