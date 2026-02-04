#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat X[481];
extern float gf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    AVComplexFloat *x_ptr = X;
    float *gf_ptr = gf;
    int n = (120 << 2) + 1;
    for (int i = 0; i < n; i++) {
        float temp_re = x_ptr[i].re * gf_ptr[i];
        float temp_im = x_ptr[i].im * gf_ptr[i];
        x_ptr[i].re = temp_re;
        x_ptr[i].im = temp_im;
    }
}
