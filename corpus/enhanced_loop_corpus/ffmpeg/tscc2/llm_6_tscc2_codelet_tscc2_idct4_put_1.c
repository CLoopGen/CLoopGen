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
    int temp[4];
    for (i = 0; i < 4; i++) {
        temp[0] = tblk[i * 4 + 0];
        temp[1] = tblk[i * 4 + 1];
        temp[2] = tblk[i * 4 + 2];
        temp[3] = tblk[i * 4 + 3];

        dst[0] = ((5 * (temp[0] + temp[1] + temp[2]) + 2 * temp[3]) + 32) >> 6;
        dst[1] = ((5 * (temp[0] - temp[2] - temp[3]) + 2 * temp[1]) + 32) >> 6;
        dst[2] = ((5 * (temp[0] - temp[2] + temp[3]) - 2 * temp[1]) + 32) >> 6;
        dst[3] = ((5 * (temp[0] - temp[1] + temp[2]) - 2 * temp[3]) + 32) >> 6;

        dst += stride;
    }
}
