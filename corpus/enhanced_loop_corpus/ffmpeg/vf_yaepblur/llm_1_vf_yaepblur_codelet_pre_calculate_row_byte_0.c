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
        for (int i = 0; i < width; i++) {
            for (x = i; x <= i; x++) {
                sat[x + 1] = sat[x] + src[x];
                square_sat[x + 1] = square_sat[x] + (uint64_t)src[x] * src[x];
            }
        }
        sat += sat_linesize;
        square_sat += sat_linesize;
        src += linesize;
    }
}
