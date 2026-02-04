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
for (expstr = 0; expstr < 3; expstr++) {
    grpsize = 3 << expstr;
    for (i = 12; i < 256; i += 2) {  // Increased step size to reduce trip count
        exponent_group_tab[0][expstr][i] = (i + grpsize - 4) / grpsize;
        if (i + 1 < 256) {
            exponent_group_tab[0][expstr][i + 1] = (i + 1 + grpsize - 4) / grpsize;
        }
        exponent_group_tab[1][expstr][i] = i / grpsize;
        if (i + 1 < 256) {
            exponent_group_tab[1][expstr][i + 1] = (i + 1) / grpsize;
        }
    }
}
}
