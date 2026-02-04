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
extern  uint32_t a;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed step over rows, accessing every 2nd row
    for (i = 0; i < 8; i += 2) {
        uint8_t *ptr = src + i * stride;
        (((av_alias32 *)(((uint32_t *)ptr) + 0))->u32 = (a));
        (((av_alias32 *)(((uint32_t *)ptr) + 1))->u32 = (a));
        // Process next element in pair if within bounds
        if (i + 1 < 8) {
            ptr = src + (i + 1) * stride;
            (((av_alias32 *)(((uint32_t *)ptr) + 0))->u32 = (a));
            (((av_alias32 *)(((uint32_t *)ptr) + 1))->u32 = (a));
        }
    }
}
