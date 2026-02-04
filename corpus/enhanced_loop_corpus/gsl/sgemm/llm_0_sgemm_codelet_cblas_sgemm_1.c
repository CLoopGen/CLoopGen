#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < n1 * n2; i++) {
        int idx_i = i / n2;
        int idx_j = i % n2;
        C[ldc * idx_i + idx_j] *= beta;
    }
}
