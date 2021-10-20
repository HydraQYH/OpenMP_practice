#include <iostream>
#include <omp.h>

int main(void)
{
    int sum = 0;
    omp_set_num_threads(4);
    #pragma omp parallel reduction(+:sum)
    {
        #pragma omp for
        for (int i = 0; i < 10; i++)
        {
            sum += i;   // 每一个线程都有sum的副本 且初始化为0
        }

        printf("Thread %d has sum: %d\n", omp_get_thread_num(), sum);
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}