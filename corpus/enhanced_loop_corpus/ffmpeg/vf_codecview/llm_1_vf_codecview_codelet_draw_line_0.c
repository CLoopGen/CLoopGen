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
        for (int offset = 0; offset < 2; offset++) {
            int curr_x = x + offset;
            if (curr_x > ex) break;
            y = (curr_x * f) >> 16;
            fr = (curr_x * f) & 65535;
            buf[y * stride + curr_x] += (color * (65536 - fr)) >> 16;
            if (fr)
                buf[(y + 1) * stride + curr_x] += (color * fr) >> 16;
        }
    }
}
