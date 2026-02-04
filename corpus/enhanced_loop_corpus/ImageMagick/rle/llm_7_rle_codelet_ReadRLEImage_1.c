#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_planes;
extern ssize_t i;
extern unsigned char background_color[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t idx;
    for (idx = (ssize_t)number_planes - 1; idx >= 0; idx--) {
        background_color[idx] = 0; // Reverse loop direction; no loop-carried dependency, but introduces WAR-like write-order reversal
    }
    // Original forward loop had WAW on background_color; now writes occur backward — same final state, different access pattern
}
