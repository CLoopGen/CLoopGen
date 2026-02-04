#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *arr1;
extern float *arr2;
extern int len;
extern float err;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        err += (arr1[i] - arr2[i]) * (arr1[i] - arr2[i]);
        if (i + 1 < len) {
            err += (arr1[i + 1] - arr2[i + 1]) * (arr1[i + 1] - arr2[i + 1]);
        }
    }
}
