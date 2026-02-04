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
extern uint32_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    int offset = (i & 3) * 4;
    if ((i & 3) == 0 && i > 0) {
        src += stride;
    }
    (((av_alias32 *)(src + offset))->u32 = (dcsplat));
    if (i == 15) {
        src += stride;
    }
}
}
