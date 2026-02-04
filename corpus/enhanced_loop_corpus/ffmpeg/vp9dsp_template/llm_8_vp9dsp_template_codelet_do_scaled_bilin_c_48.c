#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int dx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;
extern int imx;
extern int ioff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = w * 2;
for (x = 0; x < limit; x += 2) {
    int idx1 = ioff;
    int idx2 = ioff + 1;
    int diff = src[idx2] - src[idx1];
    int val1 = (src[idx1] + ((imx * diff + 8) >> 4));
    tmp_ptr[x] = (val1 < 255) ? val1 : 255;

    imx += dx;
    int carry = imx >> 4;
    ioff += carry;
    imx &= 15;

    if (x + 1 < limit) {
        idx2 = ioff + 1;
        diff = src[idx2] - src[ioff];
        int val2 = (src[ioff] + ((imx * diff + 8) >> 4));
        tmp_ptr[x + 1] = (val2 < 255) ? val2 : 255;

        imx += dx;
        carry = imx >> 4;
        ioff += carry;
        imx &= 15;
    }
}
}
