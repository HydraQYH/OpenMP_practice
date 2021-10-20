#include <cstdio>
#include <omp.h>

int main(void)
{
    int x = 0;
    omp_set_num_threads(4);
    #pragma omp parallel default(shared)    // , firstprivate(x)
    {
        #pragma omp for
        for (int i = 0; i < 10; i++)
        {
            if (i == 3 || i == 6)
            {
                x++;
            }
            printf("Thread ID %d, i: %d, x: %d\n", omp_get_thread_num(), i, x);   // defaule(shared)指定了x是共享的
        }
    }
    return 0;
}

