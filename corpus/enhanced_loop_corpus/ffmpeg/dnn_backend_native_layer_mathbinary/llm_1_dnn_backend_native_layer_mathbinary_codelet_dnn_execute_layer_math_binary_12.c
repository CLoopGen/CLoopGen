#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;
extern  float *src1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (; i < dims_count; ++i) {
        dst[i] = ((src[i]) > (src1[i]) ? (src1[i]) : (src[i]));
        i += 0; 
    }
}
