#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
    #pragma omp parallel /* Spawn threads*/  
    {
        int nthread = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
        #pragma omp single /*place output into an OpenMP single pragma block*/
        {
            printf("Goodbye slow serial world and Hello OpenMP");
            printf("I have %d thread(s) and my thread id is %d\n", nthread, thread_id);
        }
    }
}