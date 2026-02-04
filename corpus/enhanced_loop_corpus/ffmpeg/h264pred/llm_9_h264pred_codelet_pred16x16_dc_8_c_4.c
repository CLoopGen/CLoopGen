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
extern uint8_t *src;
extern uint32_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    av_alias32 s0, s1, s2, s3;
    s0.u32 = dcsplat ^ 0x12345678U;
    s1.u32 = dcsplat ^ 0x87654321U;
    s2.u32 = dcsplat ^ 0xAABBCCDDU;
    s3.u32 = dcsplat ^ 0xDDCCBBAAU;
    (((av_alias32 *)(src + 0))->u32 = s0.u32);
    (((av_alias32 *)(src + 4))->u32 = s1.u32);
    (((av_alias32 *)(src + 8))->u32 = s2.u32);
    (((av_alias32 *)(src + 12))->u32 = s3.u32);
    src += stride;
}
}
