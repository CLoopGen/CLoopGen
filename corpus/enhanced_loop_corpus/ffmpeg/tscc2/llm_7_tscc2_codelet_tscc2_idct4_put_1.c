#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int i;
extern int tblk[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_val = 0;
    for (i = 0; i < 4; i++) {
        int idx0 = i * 4 + 0;
        int idx1 = i * 4 + 1;
        int idx2 = i * 4 + 2;
        int idx3 = i * 4 + 3;

        int base = tblk[idx0] + (prev_val & 0xFF); 

        dst[0] = ((5 * ((base) + tblk[idx1] + tblk[idx2]) + 2 * tblk[idx3]) + 32) >> 6;
        dst[1] = ((5 * ((base) - tblk[idx2] - tblk[idx3]) + 2 * tblk[idx1]) + 32) >> 6;
        dst[2] = ((5 * ((base) - tblk[idx2] + tblk[idx3]) - 2 * tblk[idx1]) + 32) >> 6;
        dst[3] = ((5 * ((base) - tblk[idx1] + tblk[idx2]) - 2 * tblk[idx3]) + 32) >> 6;

        prev_val = dst[0]; 
        dst += stride;
    }
}
