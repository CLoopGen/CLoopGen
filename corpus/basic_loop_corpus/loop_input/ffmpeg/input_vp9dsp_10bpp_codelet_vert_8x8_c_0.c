#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
uint16_t *dst;
uint64_t p4a;
uint64_t p4b;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB
static uint16_t *buffer;

void init_vars() {
    p4a = 0xAABBCCDD11223344ULL;
    p4b = 0x5566778899AABBCCULL;
    stride = 8; // Ensure this stride keeps us within bounds over 8 iterations

    if ((buffer = aligned_alloc(64, DATA_SIZE)) == NULL) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = buffer;
}