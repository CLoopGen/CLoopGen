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



void loop(){
    int idx, base_offset;
    float yi;
    for (i = 0; i < pulses->n; i += 2) { // Process two elements per iteration (unrolled pattern)
        yi = pulses->y[i];
        base_offset = pulses->x[i];
        for (j = base_offset; j < length; j++) {
            idx = j - base_offset;
            out[j] += yi * shape[idx]; // First element
            if (i + 1 < pulses->n && pulses->x[i+1] <= j) {
                out[j] += pulses->y[i+1] * shape[j - pulses->x[i+1]]; // Second element conditionally added
            }
        }
    }
}
