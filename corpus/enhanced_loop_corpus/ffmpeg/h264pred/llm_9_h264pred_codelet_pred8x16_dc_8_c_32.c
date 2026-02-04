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
extern uint32_t dc1splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1) {
    uint32_t temp_dc0 = dc0splat ^ 0x12345678;
    uint32_t temp_dc1 = dc1splat ^ 0x87654321;
    for (int j = 0; j < 2; j++) {
        (((av_alias32 *)(((uint32_t *)(src + (i * 2 + j) * stride)) + 0))->u32 = (temp_dc0));
        (((av_alias32 *)(((uint32_t *)(src + (i * 2 + j) * stride)) + 1))->u32 = (temp_dc1));
    }
}
}
