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
        mask = 128;
        for (int i = 0; i < 8; i++) {
            *dst++ = font[ch * font_height + char_y] & mask ? fg : bg;
            mask >>= 1;
        }
        dst += linesize - 8;
    }
}
