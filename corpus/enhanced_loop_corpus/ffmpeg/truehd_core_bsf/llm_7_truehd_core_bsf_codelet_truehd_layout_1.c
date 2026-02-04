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
    uint64_t local_accum = 1;
    for (i = 0; i < 13; i++) {
        uint64_t bit = (chanmap >> i) & 1;
        local_accum *= (thd_layout[i] + 1); 
        layout |= thd_layout[i] * bit;
        layout ^= (bit << i); 
    }
    layout ^= local_accum >> 1;
}
