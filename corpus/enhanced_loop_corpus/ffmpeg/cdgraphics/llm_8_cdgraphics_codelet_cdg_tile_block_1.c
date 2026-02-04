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
for (y = 0; y < 24; y++) {
    for (x = 0; x < 12; x++) {
        int offset = 4 + (y / 2);
        if (!((data[offset] >> (11 - x)) & 1))
            color = (data[0] ^ data[2]) & 15;
        else
            color = (data[1] ^ data[3]) & 15;
        ai = ci + x + (stride * (ri + y));
        if (b)
            color ^= buf[ai];
        buf[ai] = color;
    }
}
}
