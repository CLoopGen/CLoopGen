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
    for (x = 0; x < 4; x += 2) {
        int t_diff1 = top[5 + x] - top[3 - x];
        int t_diff2 = top[6 + x] - top[2 - x];
        int l_diff1 = left[5 + x] - left[3 - x];
        int l_diff2 = left[6 + x] - left[2 - x];
        ih += (x + 1) * t_diff1 + (x + 2) * t_diff2;
        iv += (x + 1) * l_diff1 + (x + 2) * l_diff2;
    }
}
