#include <iostream>
#include <omp.h>

int main(void)
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                std::cout << "Thread " << omp_get_thread_num() << " section 0" << std::endl;
            }

            #pragma omp section
            {
                std::cout << "Thread " << omp_get_thread_num() << " section 1" << std::endl;
            }
        }

        #pragma omp sections
        {
            #pragma omp section
            {
                std::cout << "Thread " << omp_get_thread_num() << " section 2" << std::endl;
            }

            #pragma omp section
            {
                std::cout << "Thread " << omp_get_thread_num() << " section 3" << std::endl;
            }
        }
    }
    return 0;
}

