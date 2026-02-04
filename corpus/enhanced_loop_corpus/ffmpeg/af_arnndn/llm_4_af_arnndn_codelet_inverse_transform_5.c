#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern float *out;
extern AVComplexFloat y[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = 2 * (120 << 2);
    for (int i = 0; i < n; i++) {
        if (i >= 0) {
            out[i] = y[i].re / n;
        }
    }
}
