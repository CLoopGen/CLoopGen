#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t))

static uint16_t src_data[TOTAL_ELEMENTS];
static int16_t tmp_data[TOTAL_ELEMENTS];

int16_t *tmp = tmp_data;
uint16_t *src = src_data;
int tmpStride = 4;
int srcStride = 4;
int h = (TOTAL_ELEMENTS / 4) - 5; // ensures i < h+5 doesn't overflow
int pad = 10;
int i = 0;

void init_vars() {
    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        src_data[i] = (uint16_t)(i % 512);
    }
    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        tmp_data[i] = 0;
    }
}