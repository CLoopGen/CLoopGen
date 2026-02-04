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
    float sum = 0.0f;
    for (int i = 0; i < (2 * (120 << 2)); i++) {
        sum += y[i].re;
        out[i] = sum / (2 * (120 << 2));
    }
}
