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
    // Variant 2: Strided memory access pattern
    // Write to every 4th uint16_t element across a larger span, creating a strided access pattern
    // This increases cache line utilization with non-contiguous accesses
    // Each store is separated by 4 elements (8 bytes due to uint16_t), covering 8 positions like original
    for (y = 0; y < 32; y++) {
        (((av_alias64 *)(dst + 0 * 4))->u64 = (val));
        (((av_alias64 *)(dst + 1 * 4))->u64 = (val));
        (((av_alias64 *)(dst + 2 * 4))->u64 = (val));
        (((av_alias64 *)(dst + 3 * 4))->u64 = (val));
        (((av_alias64 *)(dst + 4 * 4))->u64 = (val));
        (((av_alias64 *)(dst + 5 * 4))->u64 = (val));
        (((av_alias64 *)(dst + 6 * 4))->u64 = (val));
        (((av_alias64 *)(dst + 7 * 4))->u64 = (val));
        dst += stride;
    }
}
