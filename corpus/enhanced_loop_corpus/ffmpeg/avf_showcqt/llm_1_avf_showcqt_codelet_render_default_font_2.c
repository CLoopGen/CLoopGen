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
    for (x = 0; x < width; x += width / 10) {
        uint8_t *startptr = data + 4 * x;
        for (u = 0; u < 12; u++) {
            for (v = 0; v < height; v++) {
                for (mask = 128; mask; mask >>= 1) {
                    int offset = v * linesize + height / 2 * 4 * u;
                    uint8_t *p = startptr + offset + (7 - __builtin_clz(mask)) * 4;
                    if (mask & avpriv_vga16_font[str[u] * 16 + v])
                        p[3] = 255;
                    else
                        p[3] = 0;
                }
            }
        }
    }
}
