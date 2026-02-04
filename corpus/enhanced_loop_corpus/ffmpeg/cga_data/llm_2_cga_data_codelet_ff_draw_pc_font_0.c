#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int linesize;
extern  uint8_t *font;
extern int font_height;
extern int ch;
extern int fg;
extern int bg;
extern int char_y;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing font row and unrolling mask checks
    // This variant reduces nested loop overhead and accesses font data once per row, using consecutive bit checking.
    for (char_y = 0; char_y < font_height; char_y++) {
        uint8_t pixel_row = font[ch * font_height + char_y];
        *dst++ = (pixel_row & 128) ? fg : bg;
        *dst++ = (pixel_row & 64)  ? fg : bg;
        *dst++ = (pixel_row & 32)  ? fg : bg;
        *dst++ = (pixel_row & 16)  ? fg : bg;
        *dst++ = (pixel_row & 8)   ? fg : bg;
        *dst++ = (pixel_row & 4)   ? fg : bg;
        *dst++ = (pixel_row & 2)   ? fg : bg;
        *dst++ = (pixel_row & 1)   ? fg : bg;
        dst += linesize - 8;
    }
}
