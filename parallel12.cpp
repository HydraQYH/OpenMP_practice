#include <cstdio>
#include <omp.h>

int main(void)
{
    omp_set_num_threads(2);
    // #pragma omp parallel for schedule(static, 2)
    // #pragma omp parallel for schedule(dynamic, 2)   // 类似于线程池 谁就绪了就分配给谁
    #pragma omp parallel for schedule(guided, 2)
    for (int i = 0; i < 20; i++)
    {
        // 指定size = 2后 每个线程被分配2次循环迭代
        printf("Thread ID: %d, index: %d\n", omp_get_thread_num(), i);
    }
    return 0;
}