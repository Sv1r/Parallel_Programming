#include <stdio.h>
#include <omp.h>
#include <math.h>
#define n 100000000
int main(int argc, char *argv[])
{
    static int i;
    static double x, ans, sum, step;

    step = 1.0/(double)n;
    sum = 0.0;
#pragma omp parallel private(x)
    {
#pragma omp for reduction(+:sum)
    for (i = 1; i <= n; i++) {
	x = (i - 0.5) * step;
	sum += exp(x);
      }
    }
    ans = step * sum;
//    printf("Value of the integral: %f\n", pi);
    return 0;
}