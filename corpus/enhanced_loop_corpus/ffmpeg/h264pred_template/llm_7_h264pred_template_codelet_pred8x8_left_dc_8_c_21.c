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
extern uint32_t dc0splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t prev = dc0splat;
    uint32_t current;
    for (i = 0; i < 4; i++) {
        current = prev ^ 0x12345678; // Introduce loop-carried WAW dependency
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = current);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = current);
        prev = current; // Carry dependency to next iteration
    }
}
