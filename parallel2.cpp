#include <iostream>
#include <omp.h>

int main(void)
{
    int x(0);
    // std::cin >> x;
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < x + 100; i++)
        {
            std::cout << i << " Thread: " << omp_get_thread_num() << std::endl;
        }

        #pragma omp for
        for (int i = 0; i < 50; i++)
        {
            std::cout << i + 100 << " Thread: " << omp_get_thread_num() << std::endl;
        }
        
    }
    return 0;
}
