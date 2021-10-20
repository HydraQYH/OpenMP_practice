#include <cstdio>
#include <omp.h>

int main(void)
{
    int x = 10;
    omp_set_num_threads(3);
    #pragma omp parallel shared(x)
    {
        #pragma omp for
        for (int i = 0; i < 10; i++)
        {
            if (i == 2)
            {
                x += 1;
            }
            printf("Thread ID %d, x: %d\n", omp_get_thread_num(), x);
        }
    }
    return 0;
}
