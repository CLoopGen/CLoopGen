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
extern uint16_t *dst;
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating offset pattern using index remapping
    ptrdiff_t effective_stride = stride / sizeof(uint16_t); // Convert byte stride to uint16_t count
    for (y = 0; y < 8; y++) {
        int index_base = (y & 1) ? effective_stride : 0; // Alternate base offset
        (((av_alias64 *)(dst + index_base + 0))->u64 = (val));
        (((av_alias64 *)(dst + index_base + 4))->u64 = (val));
        dst += effective_stride * 2; // Progress destination by variable strided amount
    }
}
