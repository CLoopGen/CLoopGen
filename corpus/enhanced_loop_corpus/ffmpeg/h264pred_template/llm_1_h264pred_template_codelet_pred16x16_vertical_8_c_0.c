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

extern int i;
extern uint8_t *src;
extern int stride;
extern  uint32_t a;
extern  uint32_t b;
extern  uint32_t c;
extern  uint32_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            (((av_alias32 *)(((uint32_t *)(src + idx * stride)) + 0))->u32 = (a));
            (((av_alias32 *)(((uint32_t *)(src + idx * stride)) + 1))->u32 = (b));
            (((av_alias32 *)(((uint32_t *)(src + idx * stride)) + 2))->u32 = (c));
            (((av_alias32 *)(((uint32_t *)(src + idx * stride)) + 3))->u32 = (d));
        }
    }
}
