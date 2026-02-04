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
    // Variant 1: Consecutive memory access with local accumulation before store
    float y_temp[8];
    int x_temp[8];
    const int16_t *idx = fixed_index; // Local alias for potential optimization
    for (i = 0; i < 4; i++) {
        const int pos1 = (pulse_position[i] << 2) + i;
        const int pos2 = (pulse_position[i + 4] << 2) + i;
        const float sign = idx[i] ? -1.f : 1.f;
        // Compute all values first, then store in consecutive order
        x_temp[i]      = pos1;
        x_temp[i + 4]  = pos2;
        y_temp[i]      = sign;
        y_temp[i + 4]  = (pos2 < pos1) ? -sign : sign;
    }
    // Now store to fixed_sparse in two consecutive loops for better spatial locality
    for (i = 0; i < 8; i++) {
        fixed_sparse->x[i] = x_temp[i];
        fixed_sparse->y[i] = y_temp[i];
    }
}
