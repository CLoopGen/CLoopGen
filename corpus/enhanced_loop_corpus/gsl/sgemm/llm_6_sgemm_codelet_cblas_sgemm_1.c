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
    float *restrict c_ptr = C + ldc * i;
    for (i = 0; i < n1; i++) {
        float beta_local = beta;
        for (j = 0; j < n2; j++) {
            c_ptr[j] *= beta_local;
        }
        c_ptr += ldc;
    }
}
