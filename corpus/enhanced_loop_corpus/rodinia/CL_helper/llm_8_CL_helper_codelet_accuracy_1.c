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
    int j;
    for (i = 0; i < len; i += 2) {
        float diff1 = arr1[i] - arr2[i];
        err += diff1 * diff1;
        if (i + 1 < len) {
            float diff2 = arr1[i + 1] - arr2[i + 1];
            err += diff2 * diff2;
        }
    }
}
