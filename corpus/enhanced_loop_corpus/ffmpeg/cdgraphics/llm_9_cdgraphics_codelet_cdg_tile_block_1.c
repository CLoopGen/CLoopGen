#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int b;
extern unsigned int ci;
extern unsigned int ri;
extern int color;
extern int x;
extern int y;
extern int ai;
extern int stride;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 6; y++) {
    int base_y = ci + stride * (ri + y);
    for (x = 0; x < 3; x++) {
        color = ((data[4 + y] >> (5 - x)) & 1) ? (data[1] & 15) : (data[0] & 15);
        ai = base_y + x;
        if (b)
            buf[ai] ^= color;
        else
            buf[ai] = color;
    }
}
}
