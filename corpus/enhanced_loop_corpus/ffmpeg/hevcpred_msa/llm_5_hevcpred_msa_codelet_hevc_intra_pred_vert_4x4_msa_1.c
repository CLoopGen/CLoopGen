#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < 4 && col != 3; col++) {
        if (col == 1) {
            col += 1; // Skip to next iteration early
        }
    }
}
