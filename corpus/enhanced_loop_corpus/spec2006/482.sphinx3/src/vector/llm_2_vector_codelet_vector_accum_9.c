#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *dst;
extern float32 *src;
extern int32 len;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2)
        dst[i] += src[i];
}
