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

extern uint8_t *src;
extern int stride;
extern  uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t *base = (uint32_t *)src;
    int offsets[8] = {0, 2, 4, 6, 8, 10, 12, 14}; // Simulate non-unit strided access pattern
    for (y = 0; y < 8; y++) {
        int offset = offsets[y];
        ((av_alias32 *)(base + offset))->u32 = dc;
        ((av_alias32 *)(base + offset + 1))->u32 = dc;
        base = (uint32_t *)((uint8_t *)base + stride);
    }
}
