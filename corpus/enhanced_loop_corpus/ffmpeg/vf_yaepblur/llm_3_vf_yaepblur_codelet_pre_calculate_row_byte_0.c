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
extern  uint8_t *src;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = starty; y < endy; y++) {
    for (x = 0; x < width; x += 2) {
        int idx = x;
        int next_idx = x + 1;
        if (next_idx < width) {
            sat[idx + 1] = sat[idx] + src[idx];
            sat[next_idx + 1] = sat[next_idx] + src[next_idx];
            square_sat[idx + 1] = square_sat[idx] + (uint64_t)src[idx] * src[idx];
            square_sat[next_idx + 1] = square_sat[next_idx] + (uint64_t)src[next_idx] * src[next_idx];
        } else if (idx < width) {
            sat[idx + 1] = sat[idx] + src[idx];
            square_sat[idx + 1] = square_sat[idx] + (uint64_t)src[idx] * src[idx];
        }
    }
    sat += sat_linesize;
    square_sat += sat_linesize;
    src += linesize;
}
}
