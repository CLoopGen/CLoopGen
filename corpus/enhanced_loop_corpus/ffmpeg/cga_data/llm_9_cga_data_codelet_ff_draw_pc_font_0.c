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
    int total_pixels = font_height * 8;
    int dst_offset = 0;
    for (int i = 0; i < total_pixels; i++) {
        int char_y = i >> 3;
        int bit = 7 - (i & 7);
        uint8_t pixel_data = font[ch * font_height + char_y];
        dst[dst_offset++] = (pixel_data >> bit) & 1 ? fg : bg;
        if ((i & 7) == 7) {
            dst_offset += linesize - 8;
        }
    }
}
