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
    // Variant 2: Strided Memory Access Pattern with Reverse Iteration
    // Use reverse loop index and strided access pattern to simulate different memory traversal behavior
    for (i = 2; i >= 0; i--) {
        int forward_i = 2 - i;  // Map 2→0, 1→1, 0→2 to preserve logical ordering in output
        int base_idx = 2 * forward_i;

        // Perform same computations but with reversed iteration
        int pulse = pulses[forward_i];
        fixed_sparse->x[base_idx]     = 3 * ((pulse >> 4) & 15) + forward_i;
        fixed_sparse->x[base_idx + 1] = 3 * (pulse & 15) + forward_i;
        fixed_sparse->y[base_idx]     = (pulse & 256) ? -1.0f : 1.0f;
        fixed_sparse->y[base_idx + 1] = (fixed_sparse->x[base_idx + 1] < fixed_sparse->x[base_idx]) 
                                     ? -fixed_sparse->y[base_idx] : fixed_sparse->y[base_idx];
    }
}
