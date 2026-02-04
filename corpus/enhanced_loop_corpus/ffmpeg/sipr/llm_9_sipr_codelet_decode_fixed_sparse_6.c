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
    int idx0 = 2 * i;
    int idx1 = idx0 + 1;
    int shift_val = pulses[i] >> 4;
    int lower = pulses[i] & 15;
    int upper = shift_val & 15;
    
    fixed_sparse->x[idx0] = 3 * upper + i;
    fixed_sparse->x[idx1] = 3 * lower + i;

    float sign = (pulses[i] & 256) ? -1.0f : 1.0f;
    fixed_sparse->y[idx0] = sign;
    
    fixed_sparse->y[idx1] = (fixed_sparse->x[idx1] < fixed_sparse->x[idx0]) ? -sign : sign;
}
}
