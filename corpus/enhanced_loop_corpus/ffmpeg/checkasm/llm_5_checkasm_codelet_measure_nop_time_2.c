#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern int nop_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2500; i < 7500; ++i) {
        if (nops[i] != 0) {
            nop_sum += nops[i];
        } else {
            continue;
        }
    }
}
