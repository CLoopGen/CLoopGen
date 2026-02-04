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
    float temp_err = 0.0f;
    for (i = 0; i < len; i++) {
        float diff = arr1[i] - arr2[i];
        temp_err += diff * diff;
    }
    err += temp_err;
}
