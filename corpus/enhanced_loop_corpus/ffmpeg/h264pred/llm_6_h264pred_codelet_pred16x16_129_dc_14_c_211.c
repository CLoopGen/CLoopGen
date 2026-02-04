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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t base_value = (((1 << (14 - 1)) + 1) * 281479271743489ULL);
    for (i = 0; i < 16; i++) {
        av_alias64* p0 = (av_alias64*)(src + 0);
        av_alias64* p4 = (av_alias64*)(src + 4);
        av_alias64* p8 = (av_alias64*)(src + 8);
        av_alias64* p12 = (av_alias64*)(src + 12);

        p0->u64 = base_value ^ i;
        p4->u64 = p0->u64 + 1;
        p8->u64 = p4->u64 + 1;
        p12->u64 = p8->u64 + 1;

        src += stride;
    }
}
