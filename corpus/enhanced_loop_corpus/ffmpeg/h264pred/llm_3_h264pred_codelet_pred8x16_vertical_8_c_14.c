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
    // Variant 2: Strided access with increased stride step (every other row skipped)
    for (i = 0; i < 16; i += 2) {
        uint8_t *row_start = src + i * stride;
        ((av_alias32 *)(((uint32_t *)row_start) + 0))->u32 = a;
        ((av_alias32 *)(((uint32_t *)row_start) + 1))->u32 = b;
    }
}
