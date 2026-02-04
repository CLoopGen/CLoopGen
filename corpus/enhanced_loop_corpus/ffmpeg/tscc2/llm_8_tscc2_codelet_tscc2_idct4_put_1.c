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
for (i = 0; i < 8; i++) {
    dst[0] = ((3 * (tblk[i * 4 + 0] + tblk[i * 4 + 1]) + (tblk[i * 4 + 2] - tblk[i * 4 + 3])) + 16) >> 5;
    dst[1] = ((3 * (tblk[i * 4 + 0] - tblk[i * 4 + 2]) + (tblk[i * 4 + 1] - tblk[i * 4 + 3])) + 16) >> 5;
    dst[2] = ((3 * (tblk[i * 4 + 0] - tblk[i * 4 + 1]) + (tblk[i * 4 + 2] + tblk[i * 4 + 3])) + 16) >> 5;
    dst[3] = ((3 * (tblk[i * 4 + 0] - tblk[i * 4 + 3]) - (tblk[i * 4 + 1] + tblk[i * 4 + 2])) + 16) >> 5;
    dst += stride;
}
}
