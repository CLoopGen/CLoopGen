#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *in;
int16_t *fc_cur;
int gain_code;
int subframe_size;
int i;
int16_t fc_new[40];

void init_vars() {
    subframe_size = 40;

    in = (int16_t*)aligned_alloc(32, subframe_size * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, subframe_size * sizeof(int16_t));
    fc_cur = (int16_t*)aligned_alloc(32, subframe_size * sizeof(int16_t));

    for (int j = 0; j < subframe_size; j++) {
        in[j] = rand() % 65536 - 32768;
        fc_cur[j] = rand() % 65536 - 32768;
        out[j] = 0;
    }

    for (int j = 0; j < 40; j++) {
        fc_new[j] = rand() % 65536 - 32768;
    }

    gain_code = rand() % 65536 - 32768;
}