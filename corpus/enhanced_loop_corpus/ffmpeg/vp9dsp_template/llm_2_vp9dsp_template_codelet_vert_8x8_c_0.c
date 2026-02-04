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

extern ptrdiff_t stride;
extern uint8_t *dst;
extern uint32_t p4a;
extern uint32_t p4b;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled writes
    uint8_t *d = dst;
    for (int i = 0; i < 8; i++) {
        av_alias32 *a = (av_alias32 *)(d);
        a[0].u32 = p4a;
        a[1].u32 = p4b;
        d += stride;
    }
}
