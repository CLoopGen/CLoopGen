#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

const int16_t ff_gain_val_tab[256][3] = {{0}};
const uint8_t ff_gain_exp_tab[256] = {0};

int16_t *sblock_data;
float data[40];
float zero[40];
float cba[40];
float cb1[40];
float cb2[40];
int cba_idx;
int gain;
int i;
int n;
unsigned int m[3];
float g[3];
float error;
float best_error;

void init_vars() {
    size_t idx;

    for (idx = 0; idx < 256; idx++) {
        ((uint8_t*)ff_gain_exp_tab)[idx] = (uint8_t)((idx % 12) + 1);
    }

    for (idx = 0; idx < 256; idx++) {
        ((int16_t(*)[3])ff_gain_val_tab)[idx][0] = (int16_t)(idx * 3);
        ((int16_t(*)[3])ff_gain_val_tab)[idx][1] = (int16_t)(idx * 2);
        ((int16_t(*)[3])ff_gain_val_tab)[idx][2] = (int16_t)(idx * 1);
    }

    sblock_data = (int16_t*)malloc(40 * sizeof(int16_t));
    if (!sblock_data) exit(1);

    for (i = 0; i < 40; i++) {
        data[i] = 0.0f;
        zero[i] = 0.0f;
        cba[i] = (float)(i + 1);
        cb1[i] = (float)(i + 2);
        cb2[i] = (float)(i + 3);
        sblock_data[i] = (int16_t)(i % 128);
    }

    cba_idx = 1;
    gain = 0;
    m[0] = 100;
    m[1] = 200;
    m[2] = 300;
    best_error = 1e10f;
}