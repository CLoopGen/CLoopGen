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
    len = 1048576; // 1M samples per channel
    in_bps = 2;
    is = 2;
    os = 1;

    in = (uint8_t*)aligned_alloc(16, channels * in_bps * len);
    out = (uint8_t**)calloc(channels, sizeof(uint8_t*));

    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t*)aligned_alloc(16, os * len);
    }

    for (int i = 0; i < channels * in_bps * len; i++) {
        in[i] = rand() % 256;
    }
}

void loop();