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
        uint64_t sat_accum = sat[0];
        uint64_t square_accum = square_sat[0];
        for (x = 0; x < width; x++) {
            sat_accum += src[x];
            square_accum += (uint64_t)src[x] * src[x];
            sat[x + 1] = sat_accum;
            square_sat[x + 1] = square_accum;
        }
        sat += sat_linesize;
        square_sat += sat_linesize;
        src += linesize;
    }
}
