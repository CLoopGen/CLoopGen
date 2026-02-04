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
    err = 0.0f;
    for (i = 0; i < len; ++i) {
        float diff = arr1[i] - arr2[i];
        if (diff > 0.001f || diff < -0.001f) {
            err += diff * diff;
        } else {
            continue;
        }
    }
}
