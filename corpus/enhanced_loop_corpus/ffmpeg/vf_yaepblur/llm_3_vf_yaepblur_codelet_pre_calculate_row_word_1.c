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
    for (x = 0; x < width; x += 2) {
        int idx1 = x;
        int idx2 = x + 1;
        if (idx2 < width) {
            sat[idx1 + 1] = sat[idx1] + src[idx1];
            sat[idx2 + 1] = sat[idx2] + src[idx2];
            square_sat[idx1 + 1] = square_sat[idx1] + (uint64_t)src[idx1] * src[idx1];
            square_sat[idx2 + 1] = square_sat[idx2] + (uint64_t)src[idx2] * src[idx2];
        } else if (idx1 < width) {
            sat[idx1 + 1] = sat[idx1] + src[idx1];
            square_sat[idx1 + 1] = square_sat[idx1] + (uint64_t)src[idx1] * src[idx1];
        }
    }
    sat += sat_linesize;
    square_sat += sat_linesize;
    src += linesize;
}
}
