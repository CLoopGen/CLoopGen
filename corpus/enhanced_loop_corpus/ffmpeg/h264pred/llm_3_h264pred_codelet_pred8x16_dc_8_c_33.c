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
    // Variant 2: Strided access with increased stride step, writing every other row
    for (i = 4; i < 8; i += 2) {
        uint32_t *row = (uint32_t *)(src + i * stride);
        ((av_alias32 *)(row + 0))->u32 = dc2splat;
        ((av_alias32 *)(row + 1))->u32 = dc3splat;
    }
}
