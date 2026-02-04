#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *srcU;
uint8_t *srcV;
int k;
int uvlinesize;
int i;
int j;

static uint8_t *bufferU;
static uint8_t *bufferV;

void init_vars() {
    k = 1024;
    uvlinesize = 2048;
    int total_size = k * uvlinesize;

    bufferU = (uint8_t *)aligned_alloc(32, total_size);
    bufferV = (uint8_t *)aligned_alloc(32, total_size);

    if (!bufferU || !bufferV) {
        exit(1);
    }

    srcU = bufferU;
    srcV = bufferV;

    for (int idx = 0; idx < total_size; idx++) {
        bufferU[idx] = rand() % 256;
        bufferV[idx] = rand() % 256;
    }
}