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

extern  int16_t *fixed_index;
extern AMRFixed *fixed_sparse;
extern int pulse_position[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided and indirect access using pointer arithmetic and stride of 2
    // Reorder computation to access every second element (strided pattern)
    // Simulate a different access pattern: process even indices first, then odd
    int indices[4] = {0, 2, 1, 3}; // Custom indirect access order
    for (int j = 0; j < 4; j++) {
        i = indices[j]; // Indirect loop index
        const int pos1 = (pulse_position[i] << 2) + i;
        const int pos2 = (pulse_position[i + 4] << 2) + i;
        const float sign = fixed_index[i] ? -1.f : 1.f;
        // Stride-2 access: write to i and i+4 but with non-linear iteration
        fixed_sparse->x[i]     = pos1;
        fixed_sparse->x[i+4]   = pos2;
        fixed_sparse->y[i]     = sign;
        fixed_sparse->y[i+4]   = (pos2 < pos1) ? -sign : sign;
    }
}
