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
extern  uint32_t c;
extern  uint32_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        uint32_t *base = (uint32_t *)(src + i * stride);
        ((av_alias32 *)(base + 0))->u32 = a ^ 0x12345678U;
        ((av_alias32 *)(base + 1))->u32 = b ^ 0x87654321U;
        ((av_alias32 *)(base + 2))->u32 = c ^ 0xAABBCCDDU;
        ((av_alias32 *)(base + 3))->u32 = d ^ 0xDDCCBBAAU;

        base = (uint32_t *)(src + (i + 1) * stride);
        ((av_alias32 *)(base + 0))->u32 = a ^ 0x11223344U;
        ((av_alias32 *)(base + 1))->u32 = b ^ 0x44332211U;
        ((av_alias32 *)(base + 2))->u32 = c ^ 0xCAFEBABEU;
        ((av_alias32 *)(base + 3))->u32 = d ^ 0xDEADBEEFU;
    }
}
