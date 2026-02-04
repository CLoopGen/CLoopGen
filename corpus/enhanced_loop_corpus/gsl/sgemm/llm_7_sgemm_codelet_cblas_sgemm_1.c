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
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            int idx = ldc * i + j;
            float temp = C[idx];
            temp *= beta;
            C[idx] = temp;
        }
    }
}
