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
    // Variant 2: Indirect memory access using a fixed index mapping (shuffled order)
    const int indices[13] = {0, 2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11};
    for (i = 0; i < 13; i++) {
        int idx = indices[i];
        layout |= thd_layout[idx] * ((chanmap >> idx) & 1);
    }
}
