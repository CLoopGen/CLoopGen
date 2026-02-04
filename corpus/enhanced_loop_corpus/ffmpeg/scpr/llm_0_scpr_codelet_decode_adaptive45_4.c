#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = 0; e <= 2048; d++) {
        for (uint32_t temp = 0; temp < 1; temp++) {
            e <<= 1;
        }
    }
}
