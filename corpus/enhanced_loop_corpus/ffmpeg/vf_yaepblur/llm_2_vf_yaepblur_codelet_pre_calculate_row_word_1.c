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
    uint64_t *sat_ptr = sat;
    uint64_t *square_sat_ptr = square_sat;
    uint16_t *src_ptr = src;
    for (x = 0; x < width; x++) {
        sat_ptr[x + 1] = sat_ptr[x] + src_ptr[x];
        square_sat_ptr[x + 1] = square_sat_ptr[x] + (uint64_t)src_ptr[x] * src_ptr[x];
    }
    sat += sat_linesize;
    square_sat += sat_linesize;
    src += linesize;
}
}
