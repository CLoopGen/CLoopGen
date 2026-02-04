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
int k;
for (k = 0; k < 76; k++) {
    int n = k / 2;
    if (n >= 38) continue;
    int j_start = (k & 1) ? bs : 0;
    int j_end = (k & 1) ? bs : 1;
    int i_base = bs * sipr_swaps[n][0];
    int o_base = bs * sipr_swaps[n][1];
    for (int j = j_start; j < j_end; j++) {
        int i = i_base + j;
        int o = o_base + j;
        int x = (buf[i >> 1] >> (4 * (i & 1))) & 15;
        int y = (buf[o >> 1] >> (4 * (o & 1))) & 15;
        buf[o >> 1] = (x << (4 * (o & 1))) | (buf[o >> 1] & (15 << (4 * !(o & 1))));
        buf[i >> 1] = (y << (4 * (i & 1))) | (buf[i >> 1] & (15 << (4 * !(i & 1))));
    }
}
}
