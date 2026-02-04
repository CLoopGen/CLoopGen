#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest_cb;
extern uint8_t *dest_cr;
extern int *linesize;
extern int dcu;
extern int dcv;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        dest_cb[x + y * linesize[1]] = (dcu + 4) >> 3;
        dest_cr[x + y * linesize[2]] = (dcv + 4) >> 3;
        dest_cb[x + (y+4) * linesize[1]] = (dcu + 2) >> 3;
        dest_cr[x + (y+4) * linesize[2]] = (dcv + 2) >> 3;
    }
}
}
