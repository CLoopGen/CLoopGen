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
    // Introduce loop-carried dependency: each iteration depends on previous y value
    float prev_y = 1.0f;
    for (i = 0; i < 3; i++) {
        int shifted = pulses[i] >> 4;
        int high_nibble = shifted & 15;
        int low_nibble = pulses[i] & 15;

        fixed_sparse->x[2 * i] = 3 * high_nibble + i;
        fixed_sparse->x[2 * i + 1] = 3 * low_nibble + i;

        float current_sign = (pulses[i] & 256) ? -1. : 1.;
        fixed_sparse->y[2 * i] = current_sign;

        // Now the sign propagation depends on both local condition and prior iteration
        float base_y = (i == 0) ? current_sign : prev_y;
        fixed_sparse->y[2 * i + 1] = (fixed_sparse->x[2 * i + 1] < fixed_sparse->x[2 * i]) ? -base_y : base_y;

        prev_y = fixed_sparse->y[2 * i + 1]; // WAW and RAW loop-carried dependency introduced
    }
}
