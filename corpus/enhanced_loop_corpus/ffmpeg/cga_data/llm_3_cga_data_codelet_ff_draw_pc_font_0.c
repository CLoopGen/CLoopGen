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
    // Variant 2: Strided memory write with indirect destination indexing to modify access pattern
    // Instead of incrementing dst directly, use an index variable and update in strides.
    // Also accesses font in same order but simulates non-unit stride in output via calculated addressing.
    ptrdiff_t offset = 0;
    for (char_y = 0; char_y < font_height; char_y++) {
        uint8_t font_val = font[ch * font_height + char_y];
        for (int bit = 7; bit >= 0; bit--) {
            dst[offset++] = (font_val >> bit) & 1 ? fg : bg;
        }
        offset += linesize - 8;
    }
}
