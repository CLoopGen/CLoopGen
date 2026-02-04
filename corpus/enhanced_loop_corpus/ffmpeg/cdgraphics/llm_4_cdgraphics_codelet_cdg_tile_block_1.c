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
for (y = 0; y < 12; y++) {
    for (x = 0; x < 6; x++) {
        color = ((data[4 + y] >> (5 - x)) & 1) ? (data[1] & 15) : (data[0] & 15);
        ai = ci + x + (stride * (ri + y));
        if (b)
            color ^= buf[ai];
        buf[ai] = color;
    }
}
}
