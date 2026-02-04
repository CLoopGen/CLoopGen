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
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        uint8_t *base = dst;
        for (int x = 0; x < 16; x += 4) {
            (((av_alias32 *)(base + x))->u32 = (val));
        }
        dst += stride;
        for (int x = 0; x < 16; x += 4) {
            (((av_alias32 *)(dst + x))->u32 = (val ^ (x << 24)));
        }
        dst += stride;
    }
}
