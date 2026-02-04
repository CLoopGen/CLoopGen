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



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize data access to write x and y in consecutive order for better cache locality
    int idx;
    for (i = 0; i < 3; i++) {
        idx = 2 * i;
        // Precompute pulse components
        int pulse_hi = (pulses[i] >> 4) & 15;
        int pulse_lo = pulses[i] & 15;
        int val_x0 = 3 * pulse_hi + i;
        int val_x1 = 3 * pulse_lo + i;
        float val_y0 = (pulses[i] & 256) ? -1.0f : 1.0f;

        // Write x[0], x[1] consecutively
        fixed_sparse->x[idx]     = val_x0;
        fixed_sparse->x[idx + 1] = val_x1;

        // Write y[0], y[1] consecutively
        fixed_sparse->y[idx]     = val_y0;
        fixed_sparse->y[idx + 1] = (val_x1 < val_x0) ? -val_y0 : val_y0;
    }
}
