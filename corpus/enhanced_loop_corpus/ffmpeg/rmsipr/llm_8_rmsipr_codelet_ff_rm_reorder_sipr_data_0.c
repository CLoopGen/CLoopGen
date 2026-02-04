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
for (n = 0; n < 38; n += 2) {
    int j;
    int i1 = bs * sipr_swaps[n][0];
    int o1 = bs * sipr_swaps[n][1];
    int i2 = bs * sipr_swaps[n+1][0];
    int o2 = bs * sipr_swaps[n+1][1];
    for (j = 0; j < bs; j++, i1++, o1++, i2++, o2++) {
        int x1 = (buf[i1 >> 1] >> (4 * (i1 & 1))) & 15, y1 = (buf[o1 >> 1] >> (4 * (o1 & 1))) & 15;
        buf[o1 >> 1] = (x1 << (4 * (o1 & 1))) | (buf[o1 >> 1] & (15 << (4 * !(o1 & 1))));
        buf[i1 >> 1] = (y1 << (4 * (i1 & 1))) | (buf[i1 >> 1] & (15 << (4 * !(i1 & 1))));

        if (n + 1 < 38) {
            int x2 = (buf[i2 >> 1] >> (4 * (i2 & 1))) & 15, y2 = (buf[o2 >> 1] >> (4 * (o2 & 1))) & 15;
            buf[o2 >> 1] = (x2 << (4 * (o2 & 1))) | (buf[o2 >> 1] & (15 << (4 * !(o2 & 1))));
            buf[i2 >> 1] = (y2 << (4 * (i2 & 1))) | (buf[i2 >> 1] & (15 << (4 * !(i2 & 1))));
        }
    }
}
}
