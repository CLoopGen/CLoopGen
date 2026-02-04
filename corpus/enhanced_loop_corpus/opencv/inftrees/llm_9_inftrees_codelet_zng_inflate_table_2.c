#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max = 14; max >= 2; max--) {
        uint16_t temp = count[max] + count[max - 1]; // Combine two array accesses and an addition
        if (temp > 1) {
            count[max] = temp >> 1; // Bit shift to increase arithmetic operations
            break;
        }
    }
}
