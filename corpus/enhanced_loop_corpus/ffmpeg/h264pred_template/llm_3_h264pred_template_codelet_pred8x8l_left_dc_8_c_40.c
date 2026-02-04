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
    // Variant 2: Strided access across multiple rows with reversed row traversal
    uint32_t *base = (uint32_t *)src;
    int stride32 = stride / sizeof(uint32_t);
    for (y = 7; y >= 0; y--) {  // Reverse iteration order
        uint32_t *row = base + (y * stride32);  // Compute row start using scaled stride
        ((av_alias32 *)(row + 0))->u32 = dc;
        ((av_alias32 *)(row + 1))->u32 = dc;
    }
}
