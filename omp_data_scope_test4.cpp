#include <iostream>
#include <unistd.h>
#include <omp.h>
using namespace std;

int thread_var = 777;
#pragma omp threadprivate(thread_var)

int main(void)
{
    omp_set_num_threads(4);

    /**
     * copyprivate子句用于将线程私有副本变量的值从一个线程广播到执行同一并行区域的其他线程的同一变量。
        说明：copyprivate只能用于single指令的子句中，在一个single块的结尾处完成广播操作。
    */

    #pragma omp parallel
    {
        #pragma omp single copyprivate(thread_var)
        {
            #pragma omp critical
            {
                cout << "Thread " << omp_get_thread_num() << " execute the single section." << endl;
            }
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

