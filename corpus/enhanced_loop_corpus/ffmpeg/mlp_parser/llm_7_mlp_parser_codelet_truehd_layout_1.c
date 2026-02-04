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
    layout = 0;
    for (i = 12; i >= 0; i--) {
        layout += thd_layout[i] & ((-(uint64_t)((chanmap >> i) & 1)) & thd_layout[i]);
    }
}
