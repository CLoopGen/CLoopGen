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
    // Variant 2: Strided access with reversed iteration and increased effective stride (every other row, backward)
    for (i = 6; i >= 4; i -= 2) {
        uint32_t *ptr = (uint32_t *)(src + i * stride);
        ((av_alias32 *)(ptr + 0))->u32 = dc2splat;
        ((av_alias32 *)(ptr + 1))->u32 = dc3splat;
    }
}
