#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_step;
uint8_t *src;
int src_step;
int len;
int i;

#define DATA_SIZE (128 << 20) // 128 MB of data for sufficient runtime (~0.01 sec on modern CPU)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    len = DATA_SIZE / sizeof(uint16_t);
    src_step = sizeof(uint16_t);
    dst_step = sizeof(uint16_t);

    src_buffer = aligned_alloc(32, DATA_SIZE);
    dst_buffer = aligned_alloc(32, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = rand() % 256;
    }

    src = src_buffer;
    dst = dst_buffer;
}