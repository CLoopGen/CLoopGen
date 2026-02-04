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
    uint32_t temp1, temp2;
    for (i = 0; i < 4; i++) {
        temp1 = dc0splat ^ (i << 8); // Introduce dependency on loop index
        temp2 = dc0splat ^ (i << 16);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = temp1);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = temp2);
    }
}
