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
    for (int y1 = 0; y1 < 16; y1++) {
        for (int y2 = 0; y2 < 2; y2++) {
            int base_offset = (y1 * 2 + y2) * 4;
            ((av_alias32 *)(dst + base_offset))->u32 = val;
        }
        if ((y1 & 1) == 1) {
            dst += stride;
        }
    }
}
