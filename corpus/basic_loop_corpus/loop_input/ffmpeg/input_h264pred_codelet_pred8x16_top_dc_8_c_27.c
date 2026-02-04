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

ptrdiff_t stride;
int i;
uint32_t dc0splat;
uint32_t dc1splat;
uint8_t *src;

void init_vars() {
    dc0splat = 0xCAFEBABE;
    dc1splat = 0xDEADBEEF;
    stride = 8; // ensures two uint32_t writes per row fit within stride

    size_t total_size = 16 * stride; // 16 rows of 'stride' bytes
    src = aligned_alloc(32, total_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < total_size; idx++) {
        src[idx] = 0;
    }
}

__attribute__((destructor))
void cleanup() {
    if (src) {
        free(src);
        src = NULL;
    }
}