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
extern uint32_t p4c;
extern uint32_t p4d;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with incremental pointer arithmetic
    uint8_t *d = dst;
    for (y = 0; y < 16; y++) {
        av_alias32 *a = (av_alias32 *)d;
        a[0].u32 = p4a;
        a[1].u32 = p4b;
        a[2].u32 = p4c;
        a[3].u32 = p4d;
        d += stride;
    }
}
