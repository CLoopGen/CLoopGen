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

extern uint16_t *src;
extern int stride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint16_t *src_local = src;
    for (i = 0; i < 8; i++) {
        av_alias64 *a64_0 = (av_alias64*)(src_local);
        av_alias64 *a64_1 = (av_alias64*)(src_local + 4);
        a64_0->u64 = ((1 << (9 - 1)) * 281479271743489ULL);
        a64_1->u64 = ((1 << (9 - 1)) * 281479271743489ULL);
        src_local += stride;
    }
}
