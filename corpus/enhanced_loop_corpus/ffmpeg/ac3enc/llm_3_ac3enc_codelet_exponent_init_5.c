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
    int indices[244];
    int count = 0;
    for (int temp = 12; temp < 256; temp++) {
        indices[count++] = temp;
    }
    for (expstr = 1 - 1; expstr <= 3 - 1; expstr++) {
        grpsize = 3 << expstr;
        for (i = 0; i < 244; i++) {
            int idx = indices[i];
            exponent_group_tab[0][expstr][idx] = (idx + grpsize - 4) / grpsize;
            exponent_group_tab[1][expstr][idx] = idx / grpsize;
        }
    }
}
