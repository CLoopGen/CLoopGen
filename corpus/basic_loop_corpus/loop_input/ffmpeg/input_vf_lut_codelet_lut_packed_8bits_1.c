#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
int j;
int w = 1024;
uint16_t (*tab)[65536];
int step = 4;
int slice_start = 0;
int slice_end = 64;
uint8_t *inrow;
uint8_t *outrow;
uint8_t *inrow0;
uint8_t *outrow0;
int in_linesize = 4096;
int out_linesize = 4096;

void init_vars() {
    tab = (uint16_t(*)[65536])calloc(4, sizeof(uint16_t[65536]));
    for (int s = 0; s < 4; s++) {
        for (int idx = 0; idx < 65536; idx++) {
            tab[s][idx] = (uint16_t)(idx * (s + 1)) & 0xFFFF;
        }
    }

    size_t in_size = slice_end * in_linesize;
    size_t out_size = slice_end * out_linesize;

    inrow0 = (uint8_t*)calloc(in_size, 1);
    outrow0 = (uint8_t*)calloc(out_size, 1);

    for (size_t k = 0; k < in_size; k++) {
        inrow0[k] = rand() & 0xFF;
    }

    inrow = inrow0;
    outrow = outrow0;
}