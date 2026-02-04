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
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        if ((x + y) % 2 == 0) {
            dest_cb[x + y * linesize[1]] = dcu / 8;
        }
        if ((x + y) % 2 == 1) {
            dest_cr[x + y * linesize[2]] = dcv / 8;
        }
    }
}
}
