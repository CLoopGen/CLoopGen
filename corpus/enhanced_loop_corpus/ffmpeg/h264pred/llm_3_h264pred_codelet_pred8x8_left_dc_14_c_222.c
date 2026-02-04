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

extern ptrdiff_t stride;
extern int i;
extern uint64_t dc2splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Access memory locations through an explicitly defined index lookup table
    static const int indices[4] = {4, 5, 6, 7};
    for (i = 0; i < 4; i++) {
        int idx = indices[i];
        (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 0))->u64 = (dc2splat));
        (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 1))->u64 = (dc2splat));
    }
}
