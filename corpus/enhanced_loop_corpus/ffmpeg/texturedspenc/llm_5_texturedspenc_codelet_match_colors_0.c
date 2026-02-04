#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int dirr;
extern int dirg;
extern int dirb;
extern int dots[16];
extern int stops[4];
extern int x;
extern int y;
extern int k;
extern uint8_t color[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = 0;
    for (y = 0; y < 4; ++y) {
        int compute_stop = (y & 1); // Only compute stops on even rows
        for (x = 0; x < 4; ++x) {
            int offset = x * 4 + y * stride;
            int val = block[offset] * dirr + block[offset + 1] * dirg + block[offset + 2] * dirb;
            dots[k++] = val;
        }
        if (compute_stop) {
            int cidx = y * 4;
            stops[y] = color[cidx] * dirr + color[cidx + 1] * dirg + color[cidx + 2] * dirb;
        } else {
            stops[y] = 0;
        }
    }
}
