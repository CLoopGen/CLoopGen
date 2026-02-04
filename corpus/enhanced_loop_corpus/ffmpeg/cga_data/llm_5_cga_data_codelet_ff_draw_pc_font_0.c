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
    for (char_y = 0; char_y < font_height; char_y++) {
        uint8_t pixel_data = font[ch * font_height + char_y];
        int bit;
        for (bit = 7; bit >= 0; bit--) {
            *dst++ = (pixel_data >> bit) & 1 ? fg : bg;
        }
        dst += linesize - 8;
    }
}
