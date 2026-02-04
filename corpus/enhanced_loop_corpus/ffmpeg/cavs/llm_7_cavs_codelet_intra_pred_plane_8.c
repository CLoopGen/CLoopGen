#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *top;
extern uint8_t *left;
extern int x;
extern int ih;
extern int iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_x = 0;
    for (x = 0; x < 4; x++) {
        int delta = x - prev_x;
        if (delta == 0) delta = 1;
        ih += delta * (top[5 + x] - top[3 - x]);
        iv += delta * (left[5 + x] - left[3 - x]);
        prev_x = x;
    }
}
