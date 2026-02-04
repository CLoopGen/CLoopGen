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
            int idx_cb = x + y * linesize[1];
            int idx_cr = x + y * linesize[2];
            dest_cb[idx_cb] = (dcu + (x & 1)) / 8;
            dest_cr[idx_cr] = (dcv + (y & 1)) / 8;
        }
    }
}
