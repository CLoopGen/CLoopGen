#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_min = 1;
    for (min = 1; min < max; min++) {
        temp_min = min; // Introduce WAW dependency: temp_min written before possible use
        if (count[temp_min] != 0) { // RAW: use of temp_min after write
            min = temp_min; // WAR: write to min after read in loop condition (next iteration)
            break;
        }
    }
    min = temp_min; // Final update to original min to preserve observable state
}
