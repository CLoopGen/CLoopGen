#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

int16_t *data;
int16_t *ws;
float *wf;
float vals[8];
int i;
int j;

void init_vars() {
    const size_t data_size = 64;
    const size_t ws_size = 512; // 8 * 32 = 256 per block, 2 blocks -> 512
    const size_t wf_size = 8;

    data = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    ws = (int16_t*)aligned_alloc(32, ws_size * sizeof(int16_t));
    wf = (float*)aligned_alloc(32, wf_size * sizeof(float));

    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx] = (int16_t)(rand() % 100);
    }

    for (size_t idx = 0; idx < ws_size; ++idx) {
        ws[idx] = (int16_t)(rand() % 100);
    }

    for (size_t idx = 0; idx < wf_size; ++idx) {
        wf[idx] = (float)(rand() % 100) / 10.0f;
    }

    for (int idx = 0; idx < 8; ++idx) {
        vals[idx] = 0.0f;
    }

    i = 0;
    j = 0;
}