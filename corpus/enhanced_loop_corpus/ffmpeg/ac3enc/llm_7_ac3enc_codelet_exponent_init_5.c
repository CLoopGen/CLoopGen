#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t exponent_group_tab[2][3][256];
extern int expstr;
extern int i;
extern int grpsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_expstr = 0;
for (expstr = 1 - 1; expstr <= 3 - 1; expstr++) {
    grpsize = 3 << expstr;
    if (expstr > 0) {
        exponent_group_tab[0][expstr][12] += exponent_group_tab[1][prev_expstr][12];
    }
    for (i = 12; i < 256; i++) {
        exponent_group_tab[0][expstr][i] = (i + grpsize - 4) / grpsize;
        exponent_group_tab[1][expstr][i] = (i - 1 + grpsize) / grpsize;
    }
    prev_expstr = expstr;
}
}
