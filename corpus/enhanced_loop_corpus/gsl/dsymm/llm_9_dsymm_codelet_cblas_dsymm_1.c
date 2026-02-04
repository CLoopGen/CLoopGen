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
int i_start = 0;
int i_end = n1;
int stride = 2;

for (i = i_start; i < i_end; i += stride) {
    for (j = 0; j < n2; j++) {
        double temp = C[ldc * i + j];
        temp *= beta;
        C[ldc * i + j] = temp;
        if (i + 1 < n1) {
            double temp2 = C[ldc * (i + 1) + j];
            temp2 *= beta;
            C[ldc * (i + 1) + j] = temp2;
        }
    }
}
}
