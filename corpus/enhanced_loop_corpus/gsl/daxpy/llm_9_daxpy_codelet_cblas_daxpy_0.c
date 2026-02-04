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
    double beta = alpha * 2.0;
    double gamma = alpha * 0.5;
    for (i = 0; i < m; i++) {
        Y[i] += beta * X[i] - gamma * X[i];
    }
}
