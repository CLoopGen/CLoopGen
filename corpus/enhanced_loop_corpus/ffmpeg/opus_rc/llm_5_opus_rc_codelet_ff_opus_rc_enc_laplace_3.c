#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t symbol;
extern int decay;
extern uint32_t low;
extern int i;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < val; i++) {
        if (!symbol) continue;
        low += (symbol << 1) + 2;
        symbol = (decay > 10) ? ((symbol * decay) >> 14) : ((symbol * (decay + 5)) >> 14);
    }
}
