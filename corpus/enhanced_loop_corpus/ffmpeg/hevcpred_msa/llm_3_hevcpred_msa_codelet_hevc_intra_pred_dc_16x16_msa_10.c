#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t data[48]; // Larger array to allow strided access
    for (col = 1; col < 16; col++) {
        // Strided memory access: step by 3 through the array, wrapping if needed
        uint32_t idx = (col * 3) % 48;
        data[idx] = col;
    }
}
