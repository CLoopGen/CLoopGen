#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec runtime estimate

uint8_t *srcU;
uint8_t *srcV;
uint8_t *lut1;
uint8_t *lut2;
int k = 1024; // Block size, chosen so that total memory access fits data size
int uvlinesize = 1024;
int i;
int j;

static uint8_t internal_srcU[DATA_SIZE];
static uint8_t internal_srcV[DATA_SIZE];
static uint8_t internal_lut1[256];
static uint8_t internal_lut2[256];

void init_vars() {
    srcU = internal_srcU;
    srcV = internal_srcV;
    lut1 = internal_lut1;
    lut2 = internal_lut2;

    for (int idx = 0; idx < 256; idx++) {
        lut1[idx] = (uint8_t)((idx * 17) % 256);
        lut2[idx] = (uint8_t)((idx * 23) % 256);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        srcU[idx] = (uint8_t)(rand() & 0xFF);
        srcV[idx] = (uint8_t)(rand() & 0xFF);
    }
}