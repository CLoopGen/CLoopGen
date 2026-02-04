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
    // Variant 2: Strided memory access by unrolling and accessing every second element first, then the others
    int16_t *local_buf = buf;
    const int *pos = optim.pulse_pos;
    const int *sign = optim.pulse_sign;
    int stride = 2;

    // First pass: even indices
    for (i = 0; i < pulse_cnt; i += stride) {
        local_buf[pos[i]] = sign[i];
    }

    // Second pass: odd indices
    for (i = 1; i < pulse_cnt; i += stride) {
        local_buf[pos[i]] = sign[i];
    }
}
