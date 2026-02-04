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
    int y;
    for (y = 0; y < 64; y++) {
        int x = y % 8;
        int current_y = y / 8;
        dest_cb[x + current_y * linesize[1]] = dcu / 8;
        dest_cr[x + current_y * linesize[2]] = dcv / 8;
    }
}
