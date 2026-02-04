#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint64_t thd_layout[13];
extern int chanmap;
extern int i;
extern uint64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < 13; outer_i++) {
        if (outer_i == i) {
            layout |= thd_layout[i] * ((chanmap >> i) & 1);
            break;
        }
    }
}
