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
for (i = 0; i < 8; i++) {
    uint8_t *row = src + i * stride;
    for (int j = 0; j < 2; j++) {
        (((av_alias32 *)(row + j * 16 + 0))->u32 = (dcsplat));
        (((av_alias32 *)(row + j * 16 + 4))->u32 = (dcsplat));
        (((av_alias32 *)(row + j * 16 + 8))->u32 = (dcsplat));
        (((av_alias32 *)(row + j * 16 + 12))->u32 = (dcsplat));
    }
}
}
