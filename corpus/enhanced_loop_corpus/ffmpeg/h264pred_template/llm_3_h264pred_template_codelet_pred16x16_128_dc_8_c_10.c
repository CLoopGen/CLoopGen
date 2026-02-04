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
extern int i;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    uint8_t *offsets[] = {src + 0, src + 4, src + 8, src + 12};
    for (int j = 0; j < 4; j++) {
        (((av_alias32 *)(offsets[j]))->u32 = ((((1 << (8 - 1)) + 0) * 16843009U)));
    }
    src += stride;
}
}
