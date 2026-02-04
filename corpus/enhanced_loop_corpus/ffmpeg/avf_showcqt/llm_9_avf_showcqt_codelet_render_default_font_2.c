#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t avpriv_vga16_font[4096];
extern  char *str;
extern int x;
extern int u;
extern int v;
extern int mask;
extern uint8_t *data;
extern int linesize;
extern int width;
extern int height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < width; x += width / 20) {
    uint8_t *startptr = data + 4 * x;
    for (u = 0; u < 12; u++) {
        for (v = 0; v < height; v++) {
            uint8_t *p = startptr + v * linesize + height / 2 * 4 * u;
            int font_index = str[u] * 16 + v;
            int shift = 7;
            for (mask = 1; mask < 256; mask <<= 1, shift--) {
                uint8_t bit = (avpriv_vga16_font[font_index] >> shift) & 1;
                (p + 4 * (7 - shift))[3] = bit ? 255 : 0;
            }
        }
    }
}
}
