#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (int i = 0; i < dims_count; ++i) {
        temp = src[i];
        dst[i] = (temp >= 0) ? temp : -temp;
    }
}
