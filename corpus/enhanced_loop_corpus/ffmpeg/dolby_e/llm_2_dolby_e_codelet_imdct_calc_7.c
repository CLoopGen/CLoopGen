#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices only
    for (i = 0; i < n2; i += 2)
        result[i] = -result[n - i - 1];
}
