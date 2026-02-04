#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

extern float *out;
extern  AMRFixed *pulses;
extern  float *shape;
extern int length;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing shape and out with increasing j, we use a stride of 2
    // to simulate strided access. We process even indices first, then odd if needed.
    // This changes spatial locality and may affect cache performance.

    int stride = 2;
    for (i = 0; i < pulses->n; i++) {
        int offset = pulses->x[i];
        float yi = pulses->y[i];
        for (j = pulses->x[i]; j + 1 < length; j += stride) {
            out[j] += yi * shape[j - offset];
            out[j + 1] += yi * shape[j + 1 - offset];
        }
        // Handle remaining element if length is odd
        if (j < length) {
            out[j] += yi * shape[j - offset];
        }
    }
}
