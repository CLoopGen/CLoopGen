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
    uint64_t local_val[2] = {val, val ^ 0xFFFF};
    for (y = 0; y < 8; y++) {
        int idx = (y & 1);
        // Remove loop-carried dependency; each iteration uses independent data
        ((av_alias64*)(dst + 0))->u64 = local_val[idx];       // No write after write with next iter
        ((av_alias64*)(dst + 4))->u64 = local_val[1 - idx];   // Use alternate value, no RAW from prior iteration
        dst += stride;
    }
}
