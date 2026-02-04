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
uint32_t dc2splat;
uint32_t dc3splat;
uint8_t *src;

void init_vars() {
    // Set stride to accommodate at least 8 rows with 2 uint32_t elements each
    stride = 8 * sizeof(uint32_t); // Enough for 8 columns of uint32_t

    // Initialize dc values
    dc2splat = 0xdeadbeef;
    dc3splat = 0xcafebabe;

    // Allocate sufficient memory: at least (8 * stride) to cover i=7 and access two uint32_t elements
    size_t total_size = 8 * stride;
    src = (uint8_t*)aligned_alloc(32, total_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize allocated memory to zero
    for (size_t idx = 0; idx < total_size; idx++) {
        src[idx] = 0;
    }
}

// External declarations required by loop
extern ptrdiff_t stride;
extern int i;
extern uint32_t dc2splat;
extern uint32_t dc3splat;
extern uint8_t *src;