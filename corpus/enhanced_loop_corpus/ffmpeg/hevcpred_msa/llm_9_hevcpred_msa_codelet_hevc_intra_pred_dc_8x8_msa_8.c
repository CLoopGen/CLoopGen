#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t j;
    for (col = 1; col < 5; col++) {
        for (j = 0; j < 4; j++) {
            col += (j * j) % 3;
        }
    }
}
