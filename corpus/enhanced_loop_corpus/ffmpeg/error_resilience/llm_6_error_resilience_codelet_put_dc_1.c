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
        uint8_t cb_val = dcu / 8;
        uint8_t cr_val = dcv / 8;
        for (x = 0; x < 8; x++) {
            dest_cb[x + y * linesize[1]] = cb_val;
            dest_cr[x + y * linesize[2]] = cr_val;
        }
    }
}
