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
    // Variant 2: Consecutive memory access but in reverse order
    for (i = 0; i < 3; i++) {
        int rev_idx = 2 - i; // Reverse index: 2, 1, 0
        fixed_sparse->x[rev_idx] = 3 * (pulses[i] & 15) + i;
        fixed_sparse->y[rev_idx] = (pulses[i] & 16) ? -1 : 1;
    }
}
