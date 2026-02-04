#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

extern int32 ceplen;
extern float32 *cur_mean;
extern float32 *sum;
extern float32 sf;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (consecutive but in reverse order)
    // Alters memory access pattern by traversing arrays from end to beginning
    for (i = ceplen - 1; i >= 0; i--)
        cur_mean[i] = sum[i] * sf;
}
