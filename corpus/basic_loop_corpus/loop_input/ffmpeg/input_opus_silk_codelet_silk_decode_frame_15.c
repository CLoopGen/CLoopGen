#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int16_t ff_silk_stereo_weights[512] = {0};

int i;
int wi[2] = {10, 20};
int ws[2] = {30, 40};
int w[2] = {0};

void init_vars() {
    for (int idx = 0; idx < 512; ++idx) {
        ((int16_t*)ff_silk_stereo_weights)[idx] = rand() % 32767;
    }
    wi[0] = 100; wi[1] = 200;
    ws[0] = 50; ws[1] = 75;
}