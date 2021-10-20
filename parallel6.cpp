#include <cstdio>
#include <omp.h>

int counter = 100;
#pragma omp threadprivate(counter)
void increment_counter(void)
{
    // 每一个线程有一个全局变量的私有副本 定义被各个线程调用的函数时 若函数使用到全局变量的私有副本 则需要使用#pragma omp threadprivate(VAR)来声明
    counter++;
}

int main(void)
{
    increment_counter();
    omp_set_num_threads(4);
    // 则主线程中的counter为线程0中的counter
    // 除线程0外，其它线程的counter为counter初始化时的值
    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0)
        {
            increment_counter();
        }
        
        // increment_counter();
        printf("Thread ID %d, counter: %d\n", omp_get_thread_num(), counter);
    }
    printf("Main Thread counter: %d\n", counter);
    return 0;
}