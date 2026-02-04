#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
int32_t d0;
int32_t d2;
int32_t d4;
int32_t d6;
int16_t *dataptr;
int rowctr;

static int16_t *data_buffer;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data to target ~0.01s runtime
    data_buffer = aligned_alloc(16, total_size);
    if (!data_buffer) {
        exit(1);
    }
    memset(data_buffer, 0, total_size);

    for (size_t i = 0; i < total_size / sizeof(int16_t); i++) {
        data_buffer[i] = rand() % 257 - 128; 
    }

    dataptr = data_buffer;
}