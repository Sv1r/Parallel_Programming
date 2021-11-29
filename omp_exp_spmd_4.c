#include <stdio.h>
#include <omp.h>
#include <math.h>
#define n 100000000
int main(int argc, char *argv[])
{
    static int i, nthreads, tid, istart, iend;
    static double x, ans, thread_sum, step;

    step = 1.0/(double)n;
    thread_sum = 0.0;

#pragma omp parallel private(tid, x, i, istart, iend) reduction(+:thread_sum)
    {
    tid = omp_get_thread_num();    
    if (tid == 0) nthreads = omp_get_num_threads();
    istart = tid + 1;
    iend = n;
    for (i = istart; i <= iend; i+=nthreads) {
	x = (i - 0.5) * step;
	thread_sum += exp(x);
      }
    }
    ans = step * thread_sum;
    printf("Value of the integral: %f\n", ans);
    return 0;
}