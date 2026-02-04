#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint8_t t;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_t = t;
    uint8_t *local_l = l;
    size_t idx = 0;
    for (i = 0; local_l[idx] != local_t; idx++, i++) {
        // Eliminate direct loop-carried dependency on memory by using local copies
        // No WAW or WAR on global state within loop body; all ops are independent
    }
    // i is still updated as in original, preserving semantics
}
