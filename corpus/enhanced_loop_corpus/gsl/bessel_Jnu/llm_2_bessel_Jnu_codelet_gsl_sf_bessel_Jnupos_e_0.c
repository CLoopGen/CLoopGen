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
    double *Y = (double*)malloc((N+2) * sizeof(double));
    Y[0] = Ynm1;
    Y[1] = Yn;
    for (n = 1; n < N; n++) {
        Y[n+1] = 2. * (mu + n) / x * Y[n] - Y[n-1];
        Y[n-1] = Y[n];
        Y[n] = Y[n+1];
    }
    Ynp1 = Y[N+1];
    Yn = Y[N];
    Ynm1 = Y[N-1];
    free(Y);
}
