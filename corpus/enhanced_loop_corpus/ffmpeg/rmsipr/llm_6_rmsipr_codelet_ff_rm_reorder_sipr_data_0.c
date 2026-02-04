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
    int i = bs * sipr_swaps[n][0];
    int o = bs * sipr_swaps[n][1];
    for (j = 0; j < bs; j++ , i++ , o++) {
        int temp_i = i, temp_o = o;
        int x = (buf[temp_i >> 1] >> (4 * (temp_i & 1))) & 15;
        int y = (buf[temp_o >> 1] >> (4 * (temp_o & 1))) & 15;
        buf[temp_o >> 1] = (x << (4 * (temp_o & 1))) | (buf[temp_o >> 1] & (15 << (4 * !(temp_o & 1))));
        buf[temp_i >> 1] = (y << (4 * (temp_i & 1))) | (buf[temp_i >> 1] & (15 << (4 * !(temp_i & 1))));
    }
}
}
