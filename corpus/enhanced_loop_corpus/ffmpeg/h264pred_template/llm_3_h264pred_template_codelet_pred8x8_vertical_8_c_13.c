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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and alternating assignment pattern
    // This changes temporal and spatial access pattern by walking backward and swapping a/b placement
    for (i = 7; i >= 0; i--) {
        uint32_t *row = (uint32_t *)(src + i * stride);
        ((av_alias32 *)row)->u32 = (i & 1) ? b : a;       // Alternate based on index
        ((av_alias32 *)(row + 1))->u32 = (i & 1) ? a : b;
    }
}
