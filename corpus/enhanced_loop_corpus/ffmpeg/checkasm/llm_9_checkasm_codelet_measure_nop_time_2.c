#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern int nop_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count and simpler operations
    for (i = 2000; i < 8000; i++) {
        if (i % 2 == 0) {
            nop_sum += nops[i];
        }
    }
}
