#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *gauss_kernel;
extern float length;
extern float gauss_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *kernel = gauss_kernel;
    float sum_inv = 1.0f / gauss_sum;
    int len = (int)length;
    for (int i = 0; i < len; i += 4) {
        kernel[i] *= sum_inv;
        if (i + 1 < len) kernel[i + 1] *= sum_inv;
        if (i + 2 < len) kernel[i + 2] *= sum_inv;
        if (i + 3 < len) kernel[i + 3] *= sum_inv;
    }
}
