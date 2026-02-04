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
for (expstr = 0; expstr < 5; expstr++) {  // Increased outer loop trip count
    if (expstr >= 3) {
        grpsize = 3 << (expstr - 2);  // Reuse pattern with shift adjustment
    } else {
        grpsize = 3 << expstr;
    }
    for (i = 8; i < 260; i++) {  // Modified bounds and increased iterations
        int adjusted_i = (i >= 256) ? 255 : i;  // Clamp index
        int val0 = (adjusted_i + grpsize - 4) / grpsize;
        int val1 = adjusted_i / grpsize;
        // Split computation into multiple steps to increase arithmetic operations
        val0 = (val0 + val0 + val0) / 3;  // Artificially increase computation
        val1 = (val1 + val1) / 2;
        exponent_group_tab[0][expstr % 3][adjusted_i] = val0;
        exponent_group_tab[1][expstr % 3][adjusted_i] = val1;
    }
}
}
