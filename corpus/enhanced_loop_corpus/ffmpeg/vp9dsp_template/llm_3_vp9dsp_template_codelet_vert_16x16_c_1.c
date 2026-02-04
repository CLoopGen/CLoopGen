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
    // Variant 2: Strided access using array indexing with scaled offsets
    for (y = 0; y < 16; y++) {
        ptrdiff_t offset = y * stride;
        (((av_alias32 *)(dst + offset + 0))->u32 = (p4a));
        (((av_alias32 *)(dst + offset + 4))->u32 = (p4b));
        (((av_alias32 *)(dst + offset + 8))->u32 = (p4c));
        (((av_alias32 *)(dst + offset + 12))->u32 = (p4d));
    }
}
