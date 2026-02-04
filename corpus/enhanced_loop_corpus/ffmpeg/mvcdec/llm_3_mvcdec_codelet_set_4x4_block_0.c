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

extern uint8_t *dst;
extern int linesize;
extern uint32_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process one row at a time with pointer arithmetic and fixed stride
    uint8_t *row = dst;
    for (j = 0; j < 4; j++) {
        uint8_t *col_ptr = row;
        for (i = 0; i < 4; i++) {
            ((av_alias32 *)col_ptr)->u32 = pixel;
            col_ptr += 4;  // Move to next pixel in row (strided by 4 bytes)
        }
        row += linesize;  // Move to next row
    }
}
