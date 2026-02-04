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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unroll and access as contiguous 32-bit values)
    uint32_t *base = (uint32_t *)src;
    int offset = stride / sizeof(uint32_t);
    for (i = 0; i < 8; i++) {
        int idx = i * offset;
        ((av_alias32 *)(base + idx + 0))->u32 = a;
        ((av_alias32 *)(base + idx + 1))->u32 = b;
    }
}
