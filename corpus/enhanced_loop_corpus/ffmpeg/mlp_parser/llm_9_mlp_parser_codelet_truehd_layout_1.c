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
    uint64_t temp1, temp2, temp3;
    for (i = 0; i < 13; i++) {
        temp1 = (chanmap >> i) & 1;
        temp2 = thd_layout[i] * temp1;
        temp3 = temp2 & (~((uint64_t)0));
        layout |= temp3;
        layout ^= (layout >> 8);
        layout *= 17;
    }
}
