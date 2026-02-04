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
for (i = 0; i < n1; i++) {
    if (i % 2 == 0) {
        for (j = 0; j < n2; j++) {
            C[ldc * i + j] *= beta;
        }
    } else {
        for (j = n2 - 1; j >= 0; j--) {
            C[ldc * i + j] *= beta;
        }
    }
}
}
