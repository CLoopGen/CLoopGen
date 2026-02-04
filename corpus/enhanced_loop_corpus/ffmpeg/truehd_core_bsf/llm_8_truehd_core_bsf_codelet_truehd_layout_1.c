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
    for (i = 0; i < 13; i += 2) {
        uint64_t mask = (chanmap >> i) & 1;
        layout |= thd_layout[i] * mask;
        if (i + 1 < 13) {
            mask = (chanmap >> (i+1)) & 1;
            layout |= thd_layout[i+1] * mask;
        }
    }
}
