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
    for (int i = 0; i < (2 * (120 << 2)); i += 2) {
        x[i].re = in[i];
        x[i].im = 0;
        if (i + 1 < (2 * (120 << 2))) {
            x[i + 1].re = in[i + 1];
            x[i + 1].im = 0;
        }
    }
}
