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
for (i = 12; i < 16; i++) {
    uint8_t *base = src + i * stride;
    for (int j = 0; j < 8; j += 4) {
        ((av_alias32 *)(base + j))->u32 = (j < 4) ? dc6splat : dc7splat;
    }
}
}
