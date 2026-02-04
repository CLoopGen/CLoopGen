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
    for (int outer = 0; outer < 4; outer++) {
        for (int inner = 0; inner < 4; inner++) {
            int offset = inner * 4;
            (((av_alias32 *)(src + offset))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
        }
        src += stride;
    }
}
