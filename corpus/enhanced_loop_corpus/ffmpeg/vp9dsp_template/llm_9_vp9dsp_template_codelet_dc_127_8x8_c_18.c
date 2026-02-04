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
    for (y = 0; y < 4; y++) {
        uint8_t offset = (y & 3) * 8;
        (((av_alias32 *)(dst + offset))->u32 = (val ^ 0xAAAAAAAA));
        (((av_alias32 *)(dst + offset + 4))->u32 = (val ^ 0x55555555));
        dst += stride;
    }
}
