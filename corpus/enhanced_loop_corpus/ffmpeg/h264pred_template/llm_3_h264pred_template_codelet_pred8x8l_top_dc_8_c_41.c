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
for (y = 0; y < 16; y += 2) {
    uint8_t *p = src + y * (stride / 8);
    ((av_alias32*)(void*)p)->u32 = dc;
    ((av_alias32*)(void*)(p + 4))->u32 = dc;
}
}
