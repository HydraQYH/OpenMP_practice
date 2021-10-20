#include <iostream>
#include <omp.h>

int main(void)
{
    int k = 0;
    omp_set_num_threads(4);
    #pragma omp parallel for firstprivate(k), lastprivate(k)
    for (int i = 0; i < 4; i++)
    {
        // 每个线程都有一个私有的k 初始化为0
        if (i == 3)
        {
            k += 100;   // 返回执行最后一次循环的线程所hold的变量
        }
        else
        {
            k++;
        }
    }
    std::cout << k << std::endl;

    #pragma omp parallel sections firstprivate(k), lastprivate(k)
    {
        #pragma omp section
        {
            k = 200;
        }

        #pragma omp section
        {
            k = 500;
        }

        #pragma omp section
        {
            k = 700;
        }

        #pragma omp section
        {
            k = 600;    // 返回代码中执行最后一个section的线程的变量
        }
    }
    std::cout << k << std::endl;
    return 0;
}