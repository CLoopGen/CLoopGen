#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct G723_1_Subframe {
    int ad_cb_lag;
    int ad_cb_gain;
    int dirac_train;
    int pulse_sign;
    int grid_index;
    int amp_index;
    int pulse_pos;
} G723_1_Subframe;

typedef struct FCBParam {
    int min_err;
    int amp_index;
    int grid_index;
    int dirac_train;
    int pulse_pos[6];
    int pulse_sign[6];
} FCBParam;

int32_t combinatorial_table[6][30];
G723_1_Subframe *subfrm;
FCBParam *optim;
int16_t *buf;
int i;
int j;

#define BUF_SIZE (1 << 20)

void init_vars() {
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 30; ++col) {
            combinatorial_table[row][col] = rand() % 100;
        }
    }

    subfrm = (G723_1_Subframe*)calloc(1, sizeof(G723_1_Subframe));
    optim = (FCBParam*)calloc(1, sizeof(FCBParam));
    buf = (int16_t*)malloc(BUF_SIZE * sizeof(int16_t));

    subfrm->pulse_pos = 0;
    subfrm->pulse_sign = 0;
    optim->grid_index = 0;
    j = 0;

    for (int k = 0; k < BUF_SIZE; ++k) {
        buf[k] = (rand() % 3) - 1;
    }
}