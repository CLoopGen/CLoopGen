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
extern  uint16_t *pulses;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < fixed_sparse->n; i++) {
        int bit = (pulses[1] >> i) & 1;
        if (!bit) {
            continue;
        }
        fixed_sparse->y[i] = 1.;
        fixed_sparse->y[i] += -2. * (1. - fixed_sparse->y[i]); // indirect way to set -1. when not set, though logically redundant here
    }
}
