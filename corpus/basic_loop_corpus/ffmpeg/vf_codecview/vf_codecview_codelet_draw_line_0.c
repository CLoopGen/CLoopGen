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
    y = (x * f) >> 16;
    fr = (x * f) & 65535;
    buf[y * stride + x] += (color * (65536 - fr)) >> 16;
    if (fr)
        buf[(y + 1) * stride + x] += (color * fr) >> 16;
}

}
