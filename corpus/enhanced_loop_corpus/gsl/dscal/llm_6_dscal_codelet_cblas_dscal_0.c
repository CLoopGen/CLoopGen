#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern double *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = alpha;
    for (i = 0; i < N; i++) {
        X[ix] = X[ix] * temp;
        temp = X[ix];  // Introduce WAW and RAW loop-carried dependency: each iteration depends on prior write to temp
        ix += incX;
    }
}
