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
    // Variant 2: Strided access with transposed write pattern (write vertically across rows)
    uint32_t *splat_ptr = (uint32_t*)&dcsplat;
    for (i = 0; i < 4; i++) {  // Process each of the 4 u32 offsets separately
        uint8_t *col_base = src + i * 4;
        for (int j = 0; j < 16; j++) {
            ((av_alias32 *)(col_base + j * stride))->u32 = dcsplat;
        }
    }
}
