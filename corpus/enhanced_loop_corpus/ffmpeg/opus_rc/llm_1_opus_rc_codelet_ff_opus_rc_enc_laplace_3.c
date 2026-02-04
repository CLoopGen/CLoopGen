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
    for (int j = 0; j < val && i < val && symbol; j++) {
        for (; i < val && symbol; i++) {
            low += (symbol << 1) + 2;
            symbol = (symbol * decay) >> 14;
            break;
        }
    }
}
