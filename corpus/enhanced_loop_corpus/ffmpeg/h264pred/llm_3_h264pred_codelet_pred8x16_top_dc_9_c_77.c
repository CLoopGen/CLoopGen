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
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating pattern (simulate non-unit stride with offset hopping)
    for (i = 0; i < 16; i++) {
        // Access every other row with double stride, creating a strided memory footprint
        ptrdiff_t effective_stride = stride * 2;
        uint64_t *ptr = (uint64_t*)(src + i * effective_stride);
        ((av_alias64 *)(ptr + 0))->u64 = dc0splat;
        ((av_alias64 *)(ptr + 1))->u64 = dc1splat;
    }
}
