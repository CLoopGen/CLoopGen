#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

extern int32 n_el;
extern int32 i;
extern uint16 *buf16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n_el > 0) {
        *(buf16 + 0) = ((255 & (*(buf16 + 0)) >> 8) | (65280 & (*(buf16 + 0)) << 8));
        for (i = 1; i < n_el; i++) {
            uint16 prev_val = *(buf16 + i - 1); // Introduce RAW dependency from previous iteration
            uint16 curr_val = *(buf16 + i);
            uint16 use_prev = (prev_val & 1) ? (curr_val >> 8) : (curr_val << 8); // Artificial loop-carried dependency
            *(buf16 + i) = ((255 & (curr_val >> 8)) | (65280 & (curr_val << 8))) ^ (use_prev & 0xFFFF);
        }
    }
}
