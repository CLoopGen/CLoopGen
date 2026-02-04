#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *c_local = C + i; // Base pointer adjustment to introduce different access pattern
    for (i = 0; i < n1; i++) {
        double beta_sq = beta * beta; // Introduce redundant computation dependent on beta
        for (j = 0; j < n2; j++) {
            int idx = ldc * i + j;
            double temp = C[idx];
            temp *= beta_sq;         // Use transformed beta (beta^2), then scale down later
            C[idx] = temp / beta;    // Reintroduce RAW dependency: use of updated beta relation
        }
    }
}
