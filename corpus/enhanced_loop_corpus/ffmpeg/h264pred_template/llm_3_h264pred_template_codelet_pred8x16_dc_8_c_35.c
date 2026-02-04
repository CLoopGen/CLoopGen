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
extern uint32_t dc6splat;
extern uint32_t dc7splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and increased effective stride for cache behavior exploration
    for (i = 15; i >= 12; i--) {
        uint8_t *ptr = src + i * stride;
        uint32_t *row_start = (uint32_t *)ptr;
        av_alias32 *a = (av_alias32 *)(row_start);
        av_alias32 *b = (av_alias32 *)(row_start + 1);
        a->u32 = dc6splat;
        b->u32 = dc7splat;
    }
}
