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
int prev_o = -1;
int prev_val = 0;
for (n = 0; n < 38; n++) {
    int j;
    int i = bs * sipr_swaps[n][0];
    int o = bs * sipr_swaps[n][1];
    for (j = 0; j < bs; j++, i++, o++) {
        int x = (buf[i >> 1] >> (4 * (i & 1))) & 15;
        int y = (buf[o >> 1] >> (4 * (o & 1))) & 15;
        if (prev_o != -1 && (prev_o >> 1) == (o >> 1)) {
            y = (prev_val >> (4 * (o & 1))) & 15;
        }
        buf[o >> 1] = (x << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
        buf[i >> 1] = (y << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));
        prev_o = o;
        prev_val = buf[o >> 1];
    }
}
}
