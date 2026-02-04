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
for (i = 0; i < 2; i++) {
    int shifted = pulses[i] & 31;
    fixed_sparse->x[i] = 2 * shifted + i + (shifted >> 2);
    fixed_sparse->y[i] = (pulses[i] & 16) ? -fixed_sparse->pitch_fac : fixed_sparse->pitch_fac;
    fixed_sparse->x[i+1] = 2 * (pulses[i+1] & 15) + i + 1;
    fixed_sparse->y[i+1] = (pulses[i+1] & 16) ? -1.0f : 1.0f;
}
}
