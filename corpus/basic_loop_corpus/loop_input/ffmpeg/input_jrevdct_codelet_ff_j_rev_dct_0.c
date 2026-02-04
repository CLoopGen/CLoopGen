#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

int32_t tmp0;
int32_t tmp1;
int32_t tmp2;
int32_t tmp3;
int32_t tmp10;
int32_t tmp11;
int32_t tmp12;
int32_t tmp13;
int32_t z1;
int32_t z2;
int32_t z3;
int32_t z4;
int32_t z5;
int32_t d0;
int32_t d1;
int32_t d2;
int32_t d3;
int32_t d4;
int32_t d5;
int32_t d6;
int32_t d7;

int16_t *dataptr;
int rowctr;

static int16_t *data_buffer;
static size_t total_elements = (1 << 24) / sizeof(int16_t); // ~16MB of data

void init_vars() {
    data_buffer = (int16_t *)aligned_alloc(32, total_elements * sizeof(int16_t));
    if (!data_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (int16_t)(i % 257 - 128);
    }

    dataptr = data_buffer;
}