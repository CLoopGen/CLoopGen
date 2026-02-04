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
extern uint8_t *dst;
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint32_t cached_val = val ^ y;
    for (y = 0; y < 8; y++) {
        ((av_alias32 *)(local_dst + 0))->u32 = cached_val;
        ((av_alias32 *)(local_dst + 4))->u32 = cached_val;
        local_dst += stride;
        cached_val = (cached_val << 1) | (cached_val >> 31); 
    }
    dst = local_dst;
}
