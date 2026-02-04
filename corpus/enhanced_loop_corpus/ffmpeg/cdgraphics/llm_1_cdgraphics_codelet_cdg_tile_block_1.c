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
    for (y = 0; y < 72; y++) {
        x = y % 6;
        int local_y = y / 6;
        if (!((data[4 + local_y] >> (5 - x)) & 1))
            color = data[0] & 15;
        else
            color = data[1] & 15;
        ai = ci + x + (stride * (ri + local_y));
        if (b)
            color ^= buf[ai];
        buf[ai] = color;
    }
}
