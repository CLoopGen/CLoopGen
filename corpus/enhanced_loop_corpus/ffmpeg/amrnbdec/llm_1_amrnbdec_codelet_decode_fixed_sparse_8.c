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
    int outer_i;
    for (outer_i = 0; outer_i < 1; outer_i++) {
        for (i = 0; i < fixed_sparse->n; i++) {
            fixed_sparse->y[i] = (pulses[1] >> i) & 1 ? 1. : -1.;
        }
    }
}
