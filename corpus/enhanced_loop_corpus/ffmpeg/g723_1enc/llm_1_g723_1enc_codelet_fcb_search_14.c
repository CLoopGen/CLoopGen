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
    int i_outer, i_inner;
    int local_pulse_cnt = pulse_cnt;
    for (i_outer = 0; i_outer < local_pulse_cnt; i_outer += 2) {
        for (i_inner = i_outer; i_inner < i_outer + 1 && i_inner < local_pulse_cnt; i_inner++) {
            i = i_inner;
            buf[optim.pulse_pos[i]] = optim.pulse_sign[i];
        }
    }
}
