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
int stride = (n2 > 16) ? 4 : 1;
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j += stride) {
        double temp = alpha * alpha;
        B[ldb * i + j] *= temp;
        if (j + 1 < n2) B[ldb * i + j + 1] *= temp;
        if (j + 2 < n2) B[ldb * i + j + 2] *= temp;
        if (j + 3 < n2) B[ldb * i + j + 3] *= temp;
    }
}
}
