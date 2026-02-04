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
for (expstr = 1 - 1; expstr <= 3 - 1; expstr++) {
    grpsize = 3 << expstr;
    int temp1, temp2;
    for (i = 12; i < 256; i++) {
        temp1 = (i + grpsize - 4) / grpsize;
        temp2 = i / grpsize;
        exponent_group_tab[0][expstr][i] = temp1;
        exponent_group_tab[1][expstr][i] = temp2;
    }
}
}
