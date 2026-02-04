#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern  float *in;
extern AVComplexFloat x[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = 2 * (120 << 2);
    for (int i = 0; i < n; i++) {
        float val = in[i] * 1.5f + 0.1f;
        x[i].re = val - 0.1f;
        x[i].im = (val - in[i] * 1.5f) * 10.0f;
    }
}
