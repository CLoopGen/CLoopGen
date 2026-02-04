#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = (n1 > n2) ? 2 : 1;
for (i = 0; i < n1; i += stride) {
    for (j = 0; j < n2; j++) {
        double temp = B[ldb * i + j];
        temp *= alpha * alpha; // Increased arithmetic intensity
        B[ldb * i + j] = temp;
    }
}
}
