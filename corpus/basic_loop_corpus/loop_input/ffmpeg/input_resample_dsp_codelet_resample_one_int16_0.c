#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_size = 65536;
int64_t index2 = 0x100000000LL;
int64_t incr = 0x200000000LL;
int dst_index = 0;

int16_t *dst;
int16_t *src;

void init_vars() {
    dst = aligned_alloc(32, dst_size * sizeof(int16_t));
    src = aligned_alloc(32, (1 << 16) * sizeof(int16_t));

    for (int i = 0; i < dst_size; i++) {
        dst[i] = 0;
    }
    for (int i = 0; i < (1 << 16); i++) {
        src[i] = (int16_t)(i & 0xFFFF);
    }
}