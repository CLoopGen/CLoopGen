#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern float normf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int n = (120 << 2) + 1;
    for (int i = 0; i < n; i++) {
        float re_val = X[i].re;
        float im_val = X[i].im;
        float norm = normf[i];
        re_val *= norm;
        im_val *= norm;
        X[i].re = re_val;
        X[i].im = im_val;
        // Additional dummy operations to increase computational intensity
        re_val += 1.0f;
        im_val -= 1.0f;
        re_val *= 0.99f;
        X[i].re = (re_val + X[i].re) * 0.5f;
    }
}
