//Program 2: Write an OpenMP program that divides the iterations into chunks containing 2 iterations (OMP_SCHEDULE=static,2). Its input should be the number of iterations, and its output should be which iterations of a parallelized for loop are executed by which thread.
#include <stdio.h>
#include <omp.h>

int main() {
    int n=16, thread;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    printf("Enter the number of threads: ");
    scanf("%d", &thread);

    omp_set_num_threads(thread);
    printf("--------------------------------------\n");

    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < n; i++) {
        printf("Thread %d executes iteration %d\n", omp_get_thread_num(), i);
    }
    return 0;
}
/*
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ gcc -fopenmp p2.c -o p2
                                                                                      
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ ./p2                   
Enter the number of tasks: 8
Enter the number of threads: 4
--------------------------------------
Thread 2 executes iteration 4
Thread 2 executes iteration 5
Thread 0 executes iteration 0
Thread 0 executes iteration 1
Thread 3 executes iteration 6
Thread 3 executes iteration 7
Thread 1 executes iteration 2
Thread 1 executes iteration 3
                          
*/