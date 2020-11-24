#include <iostream>
#include <omp.h>
using namespace std;

int main(void)
{
    int sum = 0;
    omp_lock_t* p_lock;
    omp_init_lock(p_lock);
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        // #pragma omp single
        #pragma omp master
        {
            cout << "Execute once, thread is " << omp_get_thread_num() << endl;
        }

        // Two ways to protect shared variables
        // #pragma omp critical
        // {
        //     for (size_t i = 0; i < 800; i++)
        //     {
        //         sum++;
        //     }
        // }

        for (size_t i = 0; i < 800; i++)
        {
            #pragma omp atomic
            sum++;
            // omp_set_lock(p_lock);
            // sum++;
            // omp_unset_lock(p_lock);
            if (i == 400)
            {
                #pragma omp barrier
                cout << "thread " << omp_get_thread_num() << " barrier here" << endl;
            }
        }

        
    }
    cout << sum << endl;
    omp_destroy_lock(p_lock);
    return 0;
}