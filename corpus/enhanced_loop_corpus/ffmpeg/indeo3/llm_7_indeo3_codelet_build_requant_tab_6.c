#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t requant_tab[8][128];
extern  int8_t offsets[8];
extern  int8_t deltas[8];
extern int i;
extern int j;
extern int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i >= 0; i--) { // Reverse loop direction to eliminate original loop-carried dependencies
        step = i + 2;
        int8_t local_offset = offsets[i];   // Break potential WAR hazards by loading early
        int8_t local_delta = deltas[i];     // Load delta into local variable to minimize memory access
        for (j = 127; j >= 0; j--) {        // Inner loop also reversed — changes iteration order
            int base_val = j + local_offset;
            int aligned = (base_val / step) * step;
            requant_tab[i][j] = aligned + local_delta;
        }
    }
}
