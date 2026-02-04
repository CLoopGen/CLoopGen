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
        uint64_t src_val = src[x];
        uint64_t square_val = src_val * src_val;
        sat[x + 1] = sat[x] + src_val;
        square_sat[x + 1] = square_sat[x] + square_val;
        if (x == width - 1) break;
    }
    sat += sat_linesize;
    square_sat += sat_linesize;
    src += linesize;
}
}
