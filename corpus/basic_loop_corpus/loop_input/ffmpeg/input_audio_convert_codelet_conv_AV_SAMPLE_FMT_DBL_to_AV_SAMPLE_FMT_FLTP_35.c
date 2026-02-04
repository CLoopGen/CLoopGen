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
    in_bps = 8;
    is = 8;
    os = 4;

    in = (uint8_t *)aligned_alloc(16, (size_t)channels * in_bps * len);
    out = (uint8_t **)calloc(channels, sizeof(uint8_t *));
    
    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t *)aligned_alloc(16, (size_t)os * len);
    }

    ch = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (in) {
        free(in);
        in = NULL;
    }
    if (out) {
        for (int c = 0; c < channels; c++) {
            if (out[c]) {
                free(out[c]);
            }
        }
        free(out);
        out = NULL;
    }
}