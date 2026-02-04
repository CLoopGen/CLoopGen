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
    int prev_pos = -1;
    int accumulated = 0;
    for (i = 0; i < pulse_cnt; i++) {
        int curr_pos = optim.pulse_pos[i];
        if (prev_pos != -1 && curr_pos > prev_pos)
            buf[prev_pos] += accumulated;
        accumulated += optim.pulse_sign[i];
        buf[curr_pos] = optim.pulse_sign[i];
        prev_pos = curr_pos;
    }
    if (prev_pos != -1)
        buf[prev_pos] += accumulated;
}
