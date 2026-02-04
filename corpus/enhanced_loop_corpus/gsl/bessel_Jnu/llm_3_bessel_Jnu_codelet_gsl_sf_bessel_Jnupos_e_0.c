#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int N;
extern double mu;
extern double Ynm1;
extern double Yn;
extern double Ynp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *Y_arr = (double*)calloc(3 * N, sizeof(double));
    ptrdiff_t stride = 3;
    for (n = 1; n < N; n++) {
        Y_arr[n * stride + 2] = 2. * (mu + n) / x * Y_arr[n * stride + 1] - Y_arr[n * stride + 0];
        Y_arr[(n+1) * stride + 0] = Y_arr[n * stride + 1];
        Y_arr[(n+1) * stride + 1] = Y_arr[n * stride + 2];
    }
    Ynp1 = Y_arr[(N-1) * stride + 2];
    Yn = Y_arr[(N-1) * stride + 2];
    Ynm1 = Y_arr[(N-1) * stride + 1];
    free(Y_arr);
}
