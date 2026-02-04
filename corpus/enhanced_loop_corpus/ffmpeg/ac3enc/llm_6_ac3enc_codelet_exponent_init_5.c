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
    int temp_val_0, temp_val_1;
    for (i = 12; i < 256; i++) {
        temp_val_0 = (i + grpsize - 4) / grpsize;
        temp_val_1 = i / grpsize;
        exponent_group_tab[0][expstr][i] = temp_val_0;
        exponent_group_tab[1][expstr][i] = temp_val_1;
    }
}
}
