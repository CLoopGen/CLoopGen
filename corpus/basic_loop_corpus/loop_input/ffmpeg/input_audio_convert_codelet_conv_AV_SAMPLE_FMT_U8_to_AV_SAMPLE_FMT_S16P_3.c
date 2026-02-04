#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **out;
uint8_t *in;
int len;
int channels;
int ch;
int in_bps;
int is;
int os;

void init_vars() {
    channels = 2;
    len = 16777216; // 16M samples per channel -> ~32MB input, ensures loop runs long enough
    in_bps = 1;
    is = 1;
    os = 2;

    in = (uint8_t*)aligned_alloc(32, (size_t)channels * in_bps * len);
    out = (uint8_t**)aligned_alloc(32, (size_t)channels * sizeof(uint8_t*));

    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t*)aligned_alloc(32, (size_t)os * len);
    }

    for (int i = 0; i < channels * len; i++) {
        in[i] = rand() % 256;
    }
}