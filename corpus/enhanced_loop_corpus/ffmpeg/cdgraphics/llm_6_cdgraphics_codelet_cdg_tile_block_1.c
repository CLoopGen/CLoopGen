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
    uint8_t temp_color[6];
    for (y = 0; y < 12; y++) {
        for (x = 0; x < 6; x++) {
            if (!((data[4 + y] >> (5 - x)) & 1))
                color = data[0] & 15;
            else
                color = data[1] & 15;
            ai = ci + x + (stride * (ri + y));
            if (b)
                color ^= buf[ai];
            temp_color[x] = color;
        }
        for (x = 0; x < 6; x++) {
            ai = ci + x + (stride * (ri + y));
            buf[ai] = temp_color[x];
        }
    }
}
