#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t data[8]; // Larger array to allow strided access
    for (col = 0; col < 4; col++) {
        // Strided access: write to every second element
        data[col * 2] = col;
    }
}
