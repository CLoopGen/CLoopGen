#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FCBParam {
    int min_err;
    int amp_index;
    int grid_index;
    int dirac_train;
    int pulse_pos[6];
    int pulse_sign[6];
} FCBParam;

extern int16_t *buf;
extern FCBParam optim;
extern int pulse_cnt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    int16_t *local_buf = buf;
    const int *pos = optim.pulse_pos;
    const int *sign = optim.pulse_sign;
    for (i = 0; i < pulse_cnt; i++) {
        local_buf[pos[i]] = sign[i];
    }
}
