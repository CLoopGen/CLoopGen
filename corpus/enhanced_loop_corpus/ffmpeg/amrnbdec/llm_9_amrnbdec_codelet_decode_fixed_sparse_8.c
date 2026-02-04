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
    int double_n = fixed_sparse->n * 2;
    for (i = 0; i < double_n; i += 2) {
        if (i/2 < 10) {
            int shifted = pulses[1] >> (i/2);
            fixed_sparse->y[i/2] = (shifted & 1) ? 1.0f : -1.0f;
            fixed_sparse->x[i/2] = (shifted & 2) ? 1 : -1;
        }
    }
}
