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
for (int idx = 0; idx < 16; idx++) {
    int j = idx / 4;
    int i = idx % 4;
    (((av_alias32 *)(dst + j * linesize + i * 4))->u32 = (pixel));
}
}
