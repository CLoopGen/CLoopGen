#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int width;
extern  int linesize;
extern  int sat_linesize;
extern  int starty;
extern  int endy;
extern uint64_t *sat;
extern uint64_t *square_sat;
extern  uint16_t *src;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = starty; y < endy; y++) {
    for (x = 0; x < width; x++) {
        if (src[x] > 0) {
            sat[x + 1] = sat[x] + src[x];
            square_sat[x + 1] = square_sat[x] + (uint64_t)src[x] * src[x];
        } else {
            sat[x + 1] = sat[x];
            square_sat[x + 1] = square_sat[x];
        }
    }
    sat += sat_linesize;
    square_sat += sat_linesize;
    src += linesize;
}
}
