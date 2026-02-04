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
    for (int i = 0; i < (2 * (120 << 2)); i++) {
        x[i].re = in[i];
        x[i].im = 0;
        if (i > 100 && i < 200) {
            x[i].re *= 2.0f;
        }
    }
}
