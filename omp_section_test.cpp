#include <iostream>
#include <omp.h>
using namespace std;

int main(void)
{
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                cout << "I am section 1, and the running thread is " << omp_get_thread_num() << endl;
            }
            #pragma omp section
            {
                cout << "I am section 2, and the running thread is " << omp_get_thread_num() << endl;
            }
            #pragma omp section
            {
                cout << "I am section 3, and the running thread is " << omp_get_thread_num() << endl;
            }
            #pragma omp section
            {
                cout << "I am section 4, and the running thread is " << omp_get_thread_num() << endl;
            }
            #pragma omp section
            {
                cout << "I am section 5, and the running thread is " << omp_get_thread_num() << endl;
            }
            #pragma omp section
            {
                cout << "I am section 6, and the running thread is " << omp_get_thread_num() << endl;
            }
            #pragma omp section
            {
                cout << "I am section 7, and the running thread is " << omp_get_thread_num() << endl;
            }
            #pragma omp section
            {
                cout << "I am section 8, and the running thread is " << omp_get_thread_num() << endl;
            }
        }
    }
    return 0;
}