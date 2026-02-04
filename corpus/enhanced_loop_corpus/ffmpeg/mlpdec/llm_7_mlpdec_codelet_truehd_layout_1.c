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
    uint64_t local_layout[13];
    for (i = 0; i < 13; i++) {
        local_layout[i] = thd_layout[i] * ((chanmap >> i) & 1);
    }
    for (i = 0; i < 13; i++) {
        layout |= local_layout[i];
    }
}
