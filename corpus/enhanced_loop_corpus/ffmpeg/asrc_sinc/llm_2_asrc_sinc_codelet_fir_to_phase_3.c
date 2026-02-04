#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    for (i = 0; i < work_len; i += stride)
        work[i] *= 2.F / work_len;
    for (i = 1; i < work_len; i += stride)
        work[i] *= 2.F / work_len;
}
