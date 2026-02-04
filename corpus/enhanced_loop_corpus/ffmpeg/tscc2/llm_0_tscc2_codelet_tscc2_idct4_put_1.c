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
int j;
for (i = 0; i < 4; i++) {
    for (j = 0; j < 1; j++) { // Increased depth: introduced inner dummy loop with fixed iteration
        dst[0] = ((5 * ((tblk[i * 4 + 0]) + (tblk[i * 4 + 1]) + (tblk[i * 4 + 2])) + 2 * (tblk[i * 4 + 3])) + 32) >> 6;
        dst[1] = ((5 * ((tblk[i * 4 + 0]) - (tblk[i * 4 + 2]) - (tblk[i * 4 + 3])) + 2 * (tblk[i * 4 + 1])) + 32) >> 6;
        dst[2] = ((5 * ((tblk[i * 4 + 0]) - (tblk[i * 4 + 2]) + (tblk[i * 4 + 3])) - 2 * (tblk[i * 4 + 1])) + 32) >> 6;
        dst[3] = ((5 * ((tblk[i * 4 + 0]) - (tblk[i * 4 + 1]) + (tblk[i * 4 + 2])) - 2 * (tblk[i * 4 + 3])) + 32) >> 6;
    }
    dst += stride;
}
}
