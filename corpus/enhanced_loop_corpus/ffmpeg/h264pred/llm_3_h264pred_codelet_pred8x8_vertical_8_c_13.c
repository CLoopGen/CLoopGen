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
    // Variant 2: Strided access with reversed iteration and alternating assignment
    uint32_t *row;
    for (i = 7; i >= 0; i--) {  // Reverse loop direction (still using 'for')
        row = (uint32_t *)(src + i * stride);
        // Interleave assignments in reverse order to vary access pattern
        ((av_alias32 *)(row + 1))->u32 = b;
        ((av_alias32 *)(row + 0))->u32 = a;
    }
}
