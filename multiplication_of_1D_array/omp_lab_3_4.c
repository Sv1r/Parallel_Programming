#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define n 100000000
int main(int argc, char *argv[])
{
    static int i;
    static double s, t1, t2;
    double *x, *y;

    s = 0.15;
    x = (int *)malloc(sizeof(double)*n);
    y = (int *)malloc(sizeof(double)*n);
    for(i = 0; i < n; i++) {
      x[i] = 1.0;
      y[i] = 0.0;
    }

    t1 = omp_get_wtime();
#pragma omp parallel for
    for(i = 0; i < n; i++) {
      y[i] = s*x[i];
      }
    t2 = omp_get_wtime();

    printf("Computational time = %f\n", t2-t1);
    printf("Values of vector elements: %f\n", y[0]);
    free(x);
    free(y);
    return 0;
}