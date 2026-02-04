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
    float prev = 1.0;
    for (i = 0; i < fixed_sparse->n; i++) {
        float current = (pulses[1] >> i) & 1 ? 1. : -1.;
        fixed_sparse->y[i] = current + (i > 0 ? prev * 0.1 : 0.0);
        prev = current;
    }
}
