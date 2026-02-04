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
    if (beta == 1.0) return;
    for (i = 0; i < n1; ++i) {
        int base_index = ldc * i;
        for (j = 0; j < n2; ++j) {
            C[base_index + j] *= beta;
        }
    }
}
