#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char sipr_swaps[38][2];
extern uint8_t *buf;
extern int n;
extern int bs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 38; n++) {
    int j;
    int base_i = bs * sipr_swaps[n][0];
    int base_o = bs * sipr_swaps[n][1];
    int stride = bs >> 2;  
    if (bs >= 4) {
        for (j = 0; j < stride; j++) {
            int offset = j * 4;
            int i = base_i + offset;
            int o = base_o + offset;

            int x0 = (buf[i >> 1] >> (4 * (i & 1))) & 15, y0 = (buf[o >> 1] >> (4 * (o & 1))) & 15;
            buf[o >> 1] = (x0 << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
            buf[i >> 1] = (y0 << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));

            i++; o++;
            int x1 = (buf[i >> 1] >> (4 * (i & 1))) & 15, y1 = (buf[o >> 1] >> (4 * (o & 1))) & 15;
            buf[o >> 1] = (x1 << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
            buf[i >> 1] = (y1 << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));

            i++; o++;
            int x2 = (buf[i >> 1] >> (4 * (i & 1))) & 15, y2 = (buf[o >> 1] >> (4 * (o & 1))) & 15;
            buf[o >> 1] = (x2 << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
            buf[i >> 1] = (y2 << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));

            i++; o++;
            int x3 = (buf[i >> 1] >> (4 * (i & 1))) & 15, y3 = (buf[o >> 1] >> (4 * (o & 1))) & 15;
            buf[o >> 1] = (x3 << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
            buf[i >> 1] = (y3 << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));
        }
        for (; j < bs; j++) {
            int i = base_i + j;
            int o = base_o + j;
            int x = (buf[i >> 1] >> (4 * (i & 1))) & 15, y = (buf[o >> 1] >> (4 * (o & 1))) & 15;
            buf[o >> 1] = (x << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
            buf[i >> 1] = (y << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));
        }
    } else {
        for (j = 0; j < bs; j++) {
            int i = base_i + j;
            int o = base_o + j;
            int x = (buf[i >> 1] >> (4 * (i & 1))) & 15, y = (buf[o >> 1] >> (4 * (o & 1))) & 15;
            buf[o >> 1] = (x << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
            buf[i >> 1] = (y << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));
        }
    }
}
}
