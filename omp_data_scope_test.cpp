#include <iostream>
#include <unistd.h>
#include <omp.h>
using namespace std;

int main(void)
{
    int var = 10;
    omp_set_num_threads(8);
    // #pragma omp parallel private(var)
    // #pragma omp parallel firstprivate(var)
    // {
    //     cout << "Thread id " << omp_get_thread_num() << " var: " << var << endl;
    // }
    // lastprivate不可以和 #pragma omp parallel混用
    #pragma omp lastprivate(var)
    {
        int id = omp_get_thread_num();
        sleep(1);
        var = id;
    }
    cout << var << endl;
    return 0;
}

