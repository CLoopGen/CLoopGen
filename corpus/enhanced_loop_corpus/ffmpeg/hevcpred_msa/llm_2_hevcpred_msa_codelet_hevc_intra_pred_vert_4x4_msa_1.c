#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t indices[4] = {0, 1, 2, 3};
    for (col = 0; col < 4; col++) {
        // Indirect access using an index array
        volatile uint32_t val = indices[col];
        (void)val;
    }
}
