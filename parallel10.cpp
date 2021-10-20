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
    // 进入并行区域时，若有copyin(counter)，则每个线程会拷贝一份主线程的counter，另外线程0中的counter仍然是主线程的counter
    // 没有copyin时，不会有拷贝过程，除0号线程外，各个线程中的counter为counter初始化时的值
    #pragma omp parallel copyin(counter)
    {
        if (omp_get_thread_num() == 1)
        {
            increment_counter();
        }
        
        // increment_counter();
        printf("Thread ID %d, counter: %d\n", omp_get_thread_num(), counter);   // 主线程中的counter变为线程0中的counter
    }
    printf("Main Thread counter: %d\n", counter);
    return 0;
}