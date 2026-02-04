#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *out;
uint8_t **in;
int len;
int channels;
int ch;
int out_bps;
int is;
int os;

static size_t total_input_size = 128 * 1024 * 1024; // 128 MB target

void init_vars() {
    channels = 2;
    out_bps = 64 * 1024 * 1024; // 64 MB per channel output stride
    len = 32 * 1024 * 1024;     // 32M samples per channel
    is = 2;                     // input stride: 2 bytes (int16_t)
    os = 1;                     // output stride: 1 byte

    in = (uint8_t**)calloc(channels, sizeof(uint8_t*));
    if (!in) exit(1);

    for (int c = 0; c < channels; c++) {
        in[c] = (uint8_t*)malloc(len * is);
        if (!in[c]) exit(1);
        for (int i = 0; i < len; i++) {
            int16_t val = (rand() % 512) - 256;
            ((int16_t*)in[c])[i] = val;
        }
    }

    out = (uint8_t*)malloc(channels * out_bps + os * len);
    if (!out) exit(1);
}