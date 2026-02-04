#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with precomputed row base and step
    float *C_base;
    int stride = 2 * ldc;
    int inner_offset;
    for (i = 0; i < N; i++) {
        C_base = &(((float *)C)[2 * ldc * i]);
        C_base[2 * i] *= beta;
        C_base[2 * i + 1] = 0;
        for (j = i + 1; j < N; j++) {
            inner_offset = 2 * j;
            C_base[inner_offset] *= beta;
            C_base[inner_offset + 1] *= beta;
        }
    }
}
