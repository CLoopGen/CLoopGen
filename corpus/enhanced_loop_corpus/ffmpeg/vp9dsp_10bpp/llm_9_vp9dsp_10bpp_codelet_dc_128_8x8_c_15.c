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
for (y = 0; y < 4; y++) {
    uint64_t val_lo = val & 0xFFFFFFFFULL;
    uint64_t val_hi = (val >> 32);
    ((av_alias64*)(dst + 0))->u32[0] = (uint32_t)val_lo;
    ((av_alias64*)(dst + 0))->u32[1] = (uint32_t)val_hi;
    ((av_alias64*)(dst + 4))->u32[0] = (uint32_t)val_lo;
    ((av_alias64*)(dst + 4))->u32[1] = (uint32_t)val_hi;
    dst += stride * 2;
}
}
