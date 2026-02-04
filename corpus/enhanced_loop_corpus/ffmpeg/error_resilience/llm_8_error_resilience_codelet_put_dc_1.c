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
for (y = 0; y < 16; y += 2) {
    int x;
    for (x = 0; x < 8; x++) {
        int index_cb = x + y * linesize[1];
        int index_cr = x + y * linesize[2];
        int val_cdu = dcu / 8;
        int val_dcv = dcv / 8;
        dest_cb[index_cb] = val_cdu;
        dest_cr[index_cr] = val_dcv;
    }
}
}
