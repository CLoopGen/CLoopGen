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

ptrdiff_t stride = 16;
int i = 0;
uint16_t *src;

static uint16_t *buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    buffer = aligned_alloc(64, data_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        buffer[idx] = 0;
    }
    
    src = buffer;
}

__attribute__((destructor))
static void cleanup() {
    if (buffer) {
        free(buffer);
    }
}