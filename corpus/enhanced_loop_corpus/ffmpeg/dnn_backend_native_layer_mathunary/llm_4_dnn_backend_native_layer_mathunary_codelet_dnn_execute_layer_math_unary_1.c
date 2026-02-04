#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < dims_count; ++i) {
        float value = src[i];
        if (value < 0) {
            dst[i] = -value;
        } else {
            dst[i] = value;
        }
    }
}
