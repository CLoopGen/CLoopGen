#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src0;
extern  float *src1;
extern  float *src2;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int chunk = 16;
    int num_chunks = (len + chunk - 1) / chunk;
    for (outer_i = 0; outer_i < num_chunks; outer_i++) {
        int start = outer_i * chunk;
        int end = start + chunk < len ? start + chunk : len;
        for (i = start; i < end; i++)
            dst[i] = src0[i] * src1[i] + src2[i];
    }
}
