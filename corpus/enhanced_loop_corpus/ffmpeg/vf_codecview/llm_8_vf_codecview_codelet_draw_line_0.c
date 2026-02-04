#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ex;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= ex; x += 2) {
        y = (x * f) >> 16;
        fr = (x * f) & 65535;
        int complement = 65536 - fr;
        uint8_t color_shifted = color >> 8;
        if (x <= ex) {
            buf[y * stride + x] += color_shifted * (complement >> 8);
            if (fr) {
                buf[(y + 1) * stride + x] += color_shifted * (fr >> 8);
            }
        }
        if (x + 1 <= ex) {
            int y_next = ((x + 1) * f) >> 16;
            int fr_next = ((x + 1) * f) & 65535;
            int comp_next = 65536 - fr_next;
            buf[y_next * stride + (x + 1)] += color_shifted * (comp_next >> 8);
            if (fr_next) {
                buf[(y_next + 1) * stride + (x + 1)] += color_shifted * (fr_next >> 8);
            }
        }
    }
}
