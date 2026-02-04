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
    // Variant 2: Strided memory access with transposed pattern — write one field per iteration across rows
    uint32_t *row_start;
    for (i = 0; i < 4; i++) { // Process each of the 4 fields across all rows
        for (int j = 0; j < 16; j++) {
            row_start = (uint32_t *)(src + j * stride);
            switch (i) {
                case 0: ((av_alias32 *)(row_start + 0))->u32 = a; break;
                case 1: ((av_alias32 *)(row_start + 1))->u32 = b; break;
                case 2: ((av_alias32 *)(row_start + 2))->u32 = c; break;
                case 3: ((av_alias32 *)(row_start + 3))->u32 = d; break;
            }
        }
    }
}
