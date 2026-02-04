#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ey;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y <= ey; y++) {
    x = (y * f) >> 16;
    fr = (y * f) & 65535;
    int index = y * stride + x;
    buf[index] += (color * (65536 - fr)) >> 16;
    if (fr > 32768)
        buf[index + 1] += (color * fr) >> 16;
    else if (fr < 32768 && x > 0)
        buf[index - 1] += (color * (65536 - fr)) >> 16;
}
}
