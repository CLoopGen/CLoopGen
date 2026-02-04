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

static uint16_t *data_buffer;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    const size_t num_elements = data_size / sizeof(uint16_t);
    data_buffer = aligned_alloc(64, data_size);
    if (!data_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = data_buffer;
    stride = 16; // ensures 16-byte alignment per iteration
}

__attribute__((constructor))
static void ctor() {
    init_vars();
}