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
    size_t indices[] = {12, 4, 20, 0, 28, 8, 24, 16};
    for (int i = 0; i < 8; i++) {
        (((av_alias32 *)(dst + indices[i]))->u32 = (dc));
    }
    dst += stride;
}
}
