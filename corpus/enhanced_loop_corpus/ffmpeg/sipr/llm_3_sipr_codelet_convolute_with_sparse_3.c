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
    // Variant 2: Consecutive (Reverse Sequential) Memory Access Pattern
    // Reverse the inner loop to access memory in descending order,
    // promoting different cache behavior and potentially improving prefetching
    // in some architectures due to more predictable consecutive backward access.

    for (i = 0; i < pulses->n; i++) {
        int start = pulses->x[i];
        float yi = pulses->y[i];
        int end = (start < length) ? length - 1 : start - 1;
        for (j = end; j >= start; j--) {
            out[j] += yi * shape[j - start];
        }
    }
}
