#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double local_alpha = alpha;
for (i = 0; i < N; i++) {
    double temp_sum = 0.0;
    int jx = ix;
    for (j = i; j < N; j++) {
        temp_sum += X[jx];
        jx += incX;
    }
    Ap[((i * (2 * N - i + 1)) / 2)] += temp_sum * local_alpha * X[ix];
    ix += incX;
}
}
