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
for (i = 8; i < 16; i += 2) {
    ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = dc6splat;
    ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = dc7splat;
    ((av_alias32 *)(((uint32_t *)(src + (i+1) * stride)) + 0))->u32 = dc6splat;
    ((av_alias32 *)(((uint32_t *)(src + (i+1) * stride)) + 1))->u32 = dc7splat;
}
}
