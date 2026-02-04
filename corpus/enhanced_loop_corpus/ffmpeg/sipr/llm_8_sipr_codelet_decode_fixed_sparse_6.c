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

extern AMRFixed *fixed_sparse;
extern  int16_t *pulses;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 6; i++) {
    if (i < 3) {
        fixed_sparse->x[2 * i] = 3 * ((pulses[i] >> 4) & 15) + i;
        fixed_sparse->x[2 * i + 1] = 3 * (pulses[i] & 15) + i;
        fixed_sparse->y[2 * i] = (pulses[i] & 256) ? -1. : 1.;
        fixed_sparse->y[2 * i + 1] = (fixed_sparse->x[2 * i + 1] < fixed_sparse->x[2 * i]) ? -fixed_sparse->y[2 * i] : fixed_sparse->y[2 * i];
    } else {
        int j = i - 3;
        fixed_sparse->x[2 * j] += fixed_sparse->x[2 * j + 1];
        fixed_sparse->y[2 * j] *= 0.5f;
        fixed_sparse->y[2 * j + 1] = (fixed_sparse->y[2 * j] < 0) ? 1.0f : -1.0f;
    }
}
}
