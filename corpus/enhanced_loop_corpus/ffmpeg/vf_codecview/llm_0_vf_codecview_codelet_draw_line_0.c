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
    for (x = 0; x <= ex; x++) {
        for (int dy = 0; dy <= 1; dy++) {
            y = (x * f) >> 16;
            fr = (x * f) & 65535;
            int index = (y + dy) * stride + x;
            if (dy == 0) {
                buf[index] += (color * (65536 - fr)) >> 16;
            } else if (fr) {
                buf[index] += (color * fr) >> 16;
            }
        }
    }
}
