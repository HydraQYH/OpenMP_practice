#include <iostream>
#include <unistd.h>
#include <omp.h>
using namespace std;

int thread_var = 777;
#pragma omp threadprivate(thread_var)

// int main(void)
// {
//     omp_set_num_threads(4);

//     // thread_var在主线程中有一份
//     // thread_var是每个线程内部的私有的变量
//     // 但是 如果master thread修改了thread_var
//     // 这个修改将会反应在主线程中的thread_var上

//     #pragma omp parallel copyin(thread_var)
//     {
//         #pragma omp critical
//         {
//             cout << "Thread " << omp_get_thread_num() << " Init value: " << thread_var << endl;
//         }
        
//         // #pragma omp master
//         // {
//         //     thread_var = 777;
//         // }
//         thread_var = omp_get_thread_num();

//         #pragma omp barrier

//         #pragma omp critical
//         {
//             cout << "Thread " << omp_get_thread_num() << "Final value: " << thread_var << endl;
//         }

//     }
//     cout << "Global var:" << thread_var << endl; 
//     return 0;
// }

int main(void)
{
    omp_set_num_threads(4);

    /**
     * copyin子句用于将主线程中threadprivate变量的值拷贝到执行并行区域的各个线程的threadprivate变量中，
     * 从而使得team内的子线程都拥有和主线程同样的初始值。
    */
    
    // thread_var在主线程中有一份
    // thread_var是每个线程内部的私有的变量
    // 但是 如果master thread修改了thread_var
    // 这个修改将会反应在主线程中的thread_var上

    #pragma omp parallel copyin(thread_var)
    {
        #pragma omp critical
        {
            cout << "Thread " << omp_get_thread_num() << " Init value: " << thread_var << endl;
        }
        
        #pragma omp master
        {
            #pragma omp critical
            {
                cout << "Master Thread execute." << endl;
            }
            thread_var = 666;
        }
        if (omp_get_thread_num() != 0)
        {
            thread_var = omp_get_thread_num();
        }
        
        #pragma omp barrier

        #pragma omp critical
        {
            cout << "Thread " << omp_get_thread_num() << " Final value: " << thread_var << endl;
        }
    }
    cout << "Global var:" << thread_var << endl; 
    return 0;
}

