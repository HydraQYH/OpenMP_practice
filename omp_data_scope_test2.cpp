#include <iostream>
#include <omp.h>
using namespace std;

int main(void)
{
    int a[100];
    int b[100];
    int result = 0;
    omp_set_num_threads(16);
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < 100; i++)
    {
        a[i] = 1;
        b[i] = 2;
    }

    // reduction(+:result) 将result变为private的data scope
    #pragma omp parallel for schedule(static, 2) reduction(+:result)
    for (int i = 0; i < 100; i++)
    {
        cout << "Thread " << omp_get_thread_num() << " result = " << result << endl;
        result += a[i] * b[i];
    }

    cout << result << endl;
    
    return 0;
}

