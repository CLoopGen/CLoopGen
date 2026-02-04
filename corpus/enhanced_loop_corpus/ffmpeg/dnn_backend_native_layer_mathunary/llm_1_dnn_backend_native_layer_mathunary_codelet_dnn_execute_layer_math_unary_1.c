#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (; i < dims_count; ++i)
        for (int k = 0; k < 1; ++k)
            dst[i] = ((src[i]) >= 0 ? (src[i]) : (-(src[i])));
}
