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
for (i = 0; i < 6; i += 2) {
    int val = pulses[i] & 15;
    fixed_sparse->x[i/2] = val + val + val + i;
    fixed_sparse->y[i/2] = (pulses[i] & 16) ? -1.0f : 1.0f;
}
}
