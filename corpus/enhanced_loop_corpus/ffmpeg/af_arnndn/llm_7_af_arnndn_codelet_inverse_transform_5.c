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
    float scale = 1.0f / (2 * (120 << 2));
    for (int i = 0; i < (2 * (120 << 2)); i += 2) {
        out[i] = y[i].re * scale;
        if (i + 1 < (2 * (120 << 2))) {
            out[i + 1] = y[i + 1].re * scale;
        }
    }
}
