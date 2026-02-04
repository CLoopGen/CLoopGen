#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = 0; e <= 2048; d++) {
        e <<= 1;
        e += d * 3;
        e -= 1;
    }
}
