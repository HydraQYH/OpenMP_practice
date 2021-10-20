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
    #pragma omp parallel copyin(counter)
    {
        // 进入并行区域后 每个线程都有一个私有的counter
        // 主程序的中的counter和线程0的counter是同一个
        #pragma omp sections
        {
            #pragma omp section
            {
                // 某一个线程执行这个single section
                counter = 400;  // 将counter广播给其它线程的counter
                printf("Thread ID %d, counter: %d\n", omp_get_thread_num(), counter);
            }

            #pragma omp section
            {
                // 某一个线程执行这个single section
                counter = 200;  // 将counter广播给其它线程的counter
                printf("Thread ID %d, counter: %d\n", omp_get_thread_num(), counter);
            }

            #pragma omp section
            {
                // 某一个线程执行这个single section
                counter = 300;  // 将counter广播给其它线程的counter
                printf("Thread ID %d, counter: %d\n", omp_get_thread_num(), counter);
            }
        }

        #pragma omp single copyprivate(counter)
        {
            // 某一个线程执行这个single section
            counter = 500;  // 将counter广播给其它线程的counter
            printf("Thread ID %d, counter: %d\n", omp_get_thread_num(), counter);
        }
        
        if (omp_get_thread_num() == 0)
        {
            increment_counter();
        }
        printf("Thread ID %d, counter: %d\n", omp_get_thread_num(), counter);
    }
    printf("Main Thread counter: %d\n", counter);
    return 0;
}