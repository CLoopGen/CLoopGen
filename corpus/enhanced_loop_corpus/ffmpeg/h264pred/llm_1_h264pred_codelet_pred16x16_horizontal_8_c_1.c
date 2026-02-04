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
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            const uint32_t a = ((src[-1 + idx * stride]) * 16843009U);
            av_alias32 *base = (av_alias32*)(src + idx * stride);
            base[0].u32 = a;
            base[1].u32 = a;
            base[2].u32 = a;
            base[3].u32 = a;
        }
    }
}
