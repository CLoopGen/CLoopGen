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

int16_t *buf;
FCBParam optim;
int pulse_cnt;
int i;

void init_vars() {
    pulse_cnt = 6;
    optim.min_err = 0;
    optim.amp_index = 0;
    optim.grid_index = 0;
    optim.dirac_train = 0;

    for (int j = 0; j < pulse_cnt; j++) {
        optim.pulse_pos[j] = j;
        optim.pulse_sign[j] = (j % 2 == 0) ? 1 : -1;
    }

    size_t buf_size = 1 << 20;
    buf = aligned_alloc(32, buf_size * sizeof(int16_t));
    if (!buf) {
        exit(1);
    }

    for (size_t j = 0; j < buf_size; j++) {
        buf[j] = 0;
    }
}