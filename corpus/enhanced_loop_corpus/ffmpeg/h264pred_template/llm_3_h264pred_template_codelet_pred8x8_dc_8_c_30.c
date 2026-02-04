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
extern uint32_t dc2splat;
extern uint32_t dc3splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed offset pattern, accessing every second row
    for (i = 4; i < 8; i += 2) {
        uint8_t *row = src + i * stride;
        uint32_t *row_ptr = (uint32_t *)row;

        ((av_alias32 *)(row_ptr + 0))->u32 = dc2splat;
        ((av_alias32 *)(row_ptr + 1))->u32 = dc3splat;

        // Also process i+1 if within bounds (simulate strided with adjacent fill)
        if (i + 1 < 8) {
            uint8_t *next_row = src + (i + 1) * stride;
            uint32_t *next_row_ptr = (uint32_t *)next_row;
            ((av_alias32 *)(next_row_ptr + 0))->u32 = dc2splat;
            ((av_alias32 *)(next_row_ptr + 1))->u32 = dc3splat;
        }
    }
}
