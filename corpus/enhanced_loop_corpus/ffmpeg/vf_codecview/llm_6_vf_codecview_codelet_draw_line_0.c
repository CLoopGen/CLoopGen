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
    int temp_color = color;
    for (x = 0; x <= ex; x++) {
        y = (x * f) >> 16;
        fr = (x * f) & 65535;
        int index = y * stride + x;
        int scaled_color = (temp_color * (65536 - fr)) >> 16;
        buf[index] += scaled_color;
        if (fr) {
            buf[(y + 1) * stride + x] += (temp_color * fr) >> 16;
        }
        temp_color = (temp_color + scaled_color) & 0xFF; // Introduce WAW and RAW dependency on temp_color
    }
}
