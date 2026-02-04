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
extern  uint8_t *left;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_buffer[8][2];
    for (y = 0; y < 8; y++) {
        uint32_t p4 = (left[7 - y] * 16843009U);
        temp_buffer[y][0] = p4;
        temp_buffer[y][1] = p4;
    }
    for (y = 0; y < 8; y++) {
        (((av_alias32 *)(dst + 0))->u32 = temp_buffer[y][0]);
        (((av_alias32 *)(dst + 4))->u32 = temp_buffer[y][1]);
        dst += stride;
    }
}
