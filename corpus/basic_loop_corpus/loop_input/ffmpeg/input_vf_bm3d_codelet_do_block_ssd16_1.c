#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int src_stride;
uint16_t *srcp;
uint16_t *refp;
int block_size;
double dist;
int x;
int y;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

static uint16_t src_buffer[TOTAL_ELEMENTS];
static uint16_t ref_buffer[TOTAL_ELEMENTS];

void init_vars() {
    src_stride = 512; 
    block_size = 256;
    dist = 0.0;

    size_t rows = TOTAL_ELEMENTS / (src_stride / 2);
    if (rows < block_size) {
        block_size = (int)(rows - 1);
    }

    srcp = src_buffer;
    refp = ref_buffer;

    for (size_t i = 0; i < TOTAL_ELEMENTS; i++) {
        src_buffer[i] = (uint16_t)(i % 65535);
        ref_buffer[i] = (uint16_t)((i + 100) % 65535);
    }
}