#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp = 0;
    for (max = 15; max >= 1; max--) {
        temp += count[max];          // Introduce WAW dependency via temp accumulation
        if (temp > 0 && count[max] != 0) { // Introduce RAW: temp depends on prior updates, then use count[max]
            break;
        }
    }
    count[0] = temp; // Add side effect to eliminate loop-carried dependence on control flow only
}
