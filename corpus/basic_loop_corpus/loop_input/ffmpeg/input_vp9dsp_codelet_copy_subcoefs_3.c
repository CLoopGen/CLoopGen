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
int sz;
int bit_depth;
int n;
int16_t *scan;

void init_vars() {
    sz = 2048; // sz*sz = ~4M elements, total data size ~8-16MB depending on context
    bit_depth = 16; // choose 16 to exercise the else branch with av_alias32
    n = 0;

    out = (int16_t*)aligned_alloc(16, sz * sz * 2 * sizeof(int16_t));
    scan = (int16_t*)aligned_alloc(16, sz * sz * sizeof(int16_t));

    if (!out || !scan) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < sz * sz; i++) {
        scan[i] = i % (sz * sz); // ensure rc is within valid range
    }
}