//Program 4: Write an OpenMP program to find the prime numbers from 1 to n employing the parallel for directive. Record both serial and parallel execution times.
#include <stdio.h>
#include <omp.h>
#include <time.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int n = 10000000;
    clock_t start, end;
    double cpu_time;

    printf("The range of numbers is 1 to %d\n", n);
    printf("--------------------------------------\n");
    // Serial execution
    start = clock();
    for (int i = 1; i <= n; i++) {
        is_prime(i);
    }
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time to compute prime numbers serially: %f\n", cpu_time);

    // Parallel execution
    start = clock();
    #pragma omp parallel for
    for (int i = 1; i <= n; i++) {
        is_prime(i);
    }
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time to compute prime numbers parallel: %f\n", cpu_time);

    return 0;
}
/*
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ gcc p4.c
                                                                                      
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ ./a.out 
The range of numbers is 1 to 10000000
--------------------------------------
Time to compute prime numbers serially: 7.624169
Time to compute prime numbers parallel: 3.586184

*/
