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
for (y = 0; y < 32; y++) {
    uint32_t temp_a = p4a + (y << 2);
    uint32_t temp_b = p4b + (y << 3);
    uint32_t temp_c = p4c + (y * 5);
    uint32_t temp_d = p4d + (y * 7);
    (((av_alias32 *)(dst + 0))->u32 = temp_a);
    (((av_alias32 *)(dst + 4))->u32 = temp_b);
    (((av_alias32 *)(dst + 8))->u32 = temp_c);
    (((av_alias32 *)(dst + 12))->u32 = temp_d);
    dst += stride / 2;
}
}
