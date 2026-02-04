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
extern uint16_t *src;
extern uint64_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed pattern (access columns instead of rows)
    uint16_t *base_src = src;
    ptrdiff_t effective_stride = stride / sizeof(uint16_t); // Convert byte stride to element count
    for (i = 0; i < 16; i++) {
        // Access memory with stride applied per column-like traversal
        uint16_t *p0 = base_src + i;
        uint16_t *p4 = base_src + i + 4 * effective_stride;
        uint16_t *p8 = base_src + i + 8 * effective_stride;
        uint16_t *p12 = base_src + i + 12 * effective_stride;

        ((av_alias64 *)p0)->u64 = dcsplat;
        ((av_alias64 *)p4)->u64 = dcsplat;
        ((av_alias64 *)p8)->u64 = dcsplat;
        ((av_alias64 *)p12)->u64 = dcsplat;
    }
}
