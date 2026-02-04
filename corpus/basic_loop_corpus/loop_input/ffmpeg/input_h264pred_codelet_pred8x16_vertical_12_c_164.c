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

int i;
uint16_t *src;
int stride;
uint64_t a = 0x1122334455667788ULL;
uint64_t b = 0x99AABBCCDDEEFF00ULL;

static uint16_t *internal_src_buffer;
static size_t total_data_size = 16 * 1024 * 1024; // 16 MB to target ~0.01 sec runtime

void init_vars() {
    stride = 8; // each row advances by 8 uint16_t elements (16 bytes), aligned for two uint64_t writes
    
    internal_src_buffer = (uint16_t*)aligned_alloc(64, total_data_size);
    if (!internal_src_buffer) {
        exit(1);
    }
    
    src = internal_src_buffer;
}

__attribute__((destructor))
static void cleanup() {
    if (internal_src_buffer) {
        free(internal_src_buffer);
    }
}