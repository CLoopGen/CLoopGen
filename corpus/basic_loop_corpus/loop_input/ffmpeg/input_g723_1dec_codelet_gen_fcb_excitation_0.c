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

int32_t combinatorial_table[6][30];
int16_t fixed_cb_gain[24];
int16_t *vector;
G723_1_Subframe *subfrm;
int temp;
int i;
int j;

void init_vars() {
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 30; ++col) {
            combinatorial_table[row][col] = (int32_t)(row * 30 + col + 1);
        }
    }

    for (int idx = 0; idx < 24; ++idx) {
        fixed_cb_gain[idx] = (int16_t)(idx + 1);
    }

    vector = (int16_t*)calloc(120, sizeof(int16_t));
    if (!vector) exit(1);

    subfrm = (G723_1_Subframe*)malloc(sizeof(G723_1_Subframe));
    if (!subfrm) exit(1);

    subfrm->pulse_sign = 0x3F;
    subfrm->grid_index = 0;
    subfrm->amp_index = 0;

    temp = 1000;
    i = 0;
    j = 0;
}