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
    len = 65536;
    in_bps = 4;
    is = 4;
    os = 4;

    in = (uint8_t*)calloc(len * in_bps, sizeof(uint8_t));
    out = (uint8_t**)calloc(channels, sizeof(uint8_t*));
    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t*)calloc(len * os, sizeof(uint8_t));
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}