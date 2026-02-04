#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *X;
extern double *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double factor = alpha;
    for (i = 1; i < m; i++) {
        Y[i] += factor * X[i-1];
    }
    if (m > 0) {
        Y[0] += alpha * X[0];
    }
}
