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

int16_t *out;
int16_t *in;
int sz;
int sub;
int bit_depth;
int n;
int16_t *scan;

void init_vars() {
    sz = 256;
    sub = 128;
    bit_depth = 16;
    n = 0;

    int total_size = sz * sz;
    
    out = (int16_t*)aligned_alloc(32, total_size * sizeof(int16_t) * 2);
    in = (int16_t*)aligned_alloc(32, total_size * sizeof(int16_t) * 2);
    scan = (int16_t*)aligned_alloc(32, total_size * sizeof(int16_t));

    for (int i = 0; i < total_size; i++) {
        in[i * 2] = rand() % 65536;
        in[i * 2 + 1] = rand() % 65536;
        out[i * 2] = 0;
        out[i * 2 + 1] = 0;
        scan[i] = i;
    }
}