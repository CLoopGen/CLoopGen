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
    int outer_bound = 2 * (120 << 2);
    for (int j = 0; j < outer_bound; j++) {
        for (int k = 0; k < 1; k++) {
            out[j] = y[j].re / outer_bound;
        }
    }
}
