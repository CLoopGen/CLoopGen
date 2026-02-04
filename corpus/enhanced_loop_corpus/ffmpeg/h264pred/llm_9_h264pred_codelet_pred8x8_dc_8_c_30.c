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
extern uint32_t dc2splat;
extern uint32_t dc3splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < 6; i++) {
    uint8_t *row1 = src + i * stride;
    uint8_t *row2 = src + (i + 4) * stride;
    ((av_alias32 *)(row1 + 0))->u32 = dc2splat;
    ((av_alias32 *)(row1 + 4))->u32 = dc3splat;
    ((av_alias32 *)(row2 + 0))->u32 = dc2splat;
    ((av_alias32 *)(row2 + 4))->u32 = dc3splat;
}
}
