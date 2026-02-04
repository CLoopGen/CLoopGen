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

extern uint8_t *dst;
extern int linesize;
extern uint32_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    uint8_t *row = dst + j * linesize;
    av_alias32 *a = (av_alias32 *)row;
    a[0].u32 = pixel;
    a[1].u32 = pixel;
    a[2].u32 = pixel;
    a[3].u32 = pixel;
}
}
