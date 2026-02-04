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
    uint32_t local_low = low;
    for (int j = i; j < val && symbol; j++) {
        local_low += (symbol << 1) + 2;
        uint32_t next_symbol = (symbol * decay) >> 14;
        if (next_symbol == 0) {
            symbol = 0;
            break;
        }
        symbol = next_symbol;
    }
    low = local_low;
}
