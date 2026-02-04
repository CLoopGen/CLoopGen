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
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < (120 << 2); k++) {
            int i = j * (120 << 2) + k;
            x[i].re = in[i];
            x[i].im = 0;
        }
    }
}
