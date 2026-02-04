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
    uint32_t local_dc[8];
    for (y = 0; y < 8; y++) {
        local_dc[y] = dc; // Remove loop-carried dependency by pre-storing dc
    }
    for (y = 0; y < 8; y++) {
        ((av_alias32 *)(((uint32_t *)src) + 0))->u32 = local_dc[y];
        ((av_alias32 *)(((uint32_t *)src) + 1))->u32 = local_dc[y];
        src += stride;
    }
}
