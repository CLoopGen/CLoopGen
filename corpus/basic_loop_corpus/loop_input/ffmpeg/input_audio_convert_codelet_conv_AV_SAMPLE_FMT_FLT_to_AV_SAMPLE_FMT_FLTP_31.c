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

static uint8_t *in_buffer;
static uint8_t **out_buffers;

void init_vars() {
    channels = 2;
    len = 16777216; // ~64 MB input per channel, total ~128 MB
    in_bps = sizeof(float) * len;
    is = sizeof(float);
    os = sizeof(float);

    in_buffer = calloc(len * channels, sizeof(float));
    if (!in_buffer) exit(1);

    out_buffers = malloc(channels * sizeof(uint8_t*));
    if (!out_buffers) exit(1);

    for (int c = 0; c < channels; c++) {
        out_buffers[c] = calloc(len, sizeof(float));
        if (!out_buffers[c]) exit(1);
    }

    in = in_buffer;
    out = out_buffers;
    ch = 0;
}

__attribute__((constructor)) void setup() {
    init_vars();
}