//Program 3: Write an OpenMP program to calculate n-th Fibonacci number using tasks, and also compute it serially to compare times.
#include <stdio.h>
#include <omp.h>
#include <time.h>

// Parallel Fibonacci function 
long int fib(long int n) {
    if (n < 2) return n;
    long int x, y;
    #pragma omp task shared(x)
    x = fib(n - 1);
    #pragma omp task shared(y)
    y = fib(n - 2);
    #pragma omp taskwait
    return x + y;
}
// Serial Fibonacci function
long int ser_fib(long int n) {
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
}
int main() {
    long int n = 10, result;
    clock_t start, end;
    double cpu_time;

    printf("Enter the value of n: ");
    scanf("%ld", &n);

    start = clock();
    #pragma omp parallel
    {
        #pragma omp single
        result = fib(n);
    }
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Fibonacci(%ld) = %ld\n", n, result);
    printf("The time used to execute the program in parallel mode = %f seconds\n", cpu_time);

    start = clock();
    result = ser_fib(n);
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Fibonacci(%ld) = %ld\n", n, result);
    printf("The time used to execute the program in sequential mode = %f seconds\n", cpu_time);

    return 0;
}
/*
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ gcc p3.c               
                                                                                      
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ ./a.out
Enter the value of n: 32
Fibonacci(32) = 2178309
The time used to execute the program in parallel mode = 0.036746 seconds
Fibonacci(32) = 2178309
The time used to execute the program in sequential mode = 0.035136 seconds

*/