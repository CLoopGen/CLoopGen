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

ptrdiff_t stride = 8;
int i = 0;
uint32_t a = 0xdeadbeef;
uint8_t *src = NULL;

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB to target ~0.01 sec runtime

void init_vars() {
    src = aligned_alloc(32, DATA_SIZE);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}