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

extern uint8_t *src;
extern int stride;
extern  uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint32_t *src32 = (uint32_t *)src;
    for (i = 0; i < 8; i++) {
        av_alias32 *a = (av_alias32 *)(src32 + i * (stride / sizeof(uint32_t)));
        a[0].u32 = dc;
        a[1].u32 = dc;
        src32 += stride / sizeof(uint32_t);
    }
}
