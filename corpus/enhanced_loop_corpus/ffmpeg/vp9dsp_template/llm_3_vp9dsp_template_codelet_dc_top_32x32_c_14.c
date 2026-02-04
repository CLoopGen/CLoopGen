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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 32; y++) {
    int offsets[8] = {28, 20, 4, 12, 0, 24, 16, 8};
    for (int j = 0; j < 8; j++) {
        (((av_alias32 *)(dst + offsets[j]))->u32 = (dc));
    }
    dst += stride;
}
}
