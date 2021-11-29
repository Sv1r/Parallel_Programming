#include <stdio.h>
#include <omp.h>
#include <math.h>
#define n 100000000
int main(int argc, char *argv[])
{
    static int i;
    static double x, ans, sum, thread_sum, step;

    step = 1.0/(double)n;
    sum = 0.0;
    thread_sum = 0.0;

#pragma omp parallel private(x) firstprivate(thread_sum)
    {
#pragma omp for
    for (i = 1; i <= n; i++) {
	x = (i - 0.5) * step;
	thread_sum += exp(x);
      }
#pragma omp critical
      {
        sum += thread_sum;
      }
    }
    ans = step * sum;
//    printf("Value of the integral: %f\n", pi);
    return 0;
}