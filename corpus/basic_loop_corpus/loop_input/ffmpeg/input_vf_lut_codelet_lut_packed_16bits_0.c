#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;
int w = 1024;
uint16_t (*tab)[65536];
int step = 4;
int slice_start = 0;
int slice_end = 64;
uint16_t *inrow;
uint16_t *outrow;
uint16_t *inrow0;
uint16_t *outrow0;
int in_linesize = 4096;
int out_linesize = 4096;

void init_vars() {
    tab = (uint16_t(*)[65536])calloc(4, sizeof(uint16_t) * 65536);
    for (int s = 0; s < 4; s++) {
        for (int k = 0; k < 65536; k++) {
            tab[s][k] = (uint16_t)(k ^ (s * 0x5555));
        }
    }

    inrow0 = (uint16_t*)calloc(slice_end * in_linesize + 4, sizeof(uint16_t));
    outrow0 = (uint16_t*)calloc(slice_end * out_linesize + 4, sizeof(uint16_t));

    if (!inrow0 || !outrow0 || !tab) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < slice_end * in_linesize; i++) {
        inrow0[i] = (uint16_t)(i & 0xFFFF);
    }
}