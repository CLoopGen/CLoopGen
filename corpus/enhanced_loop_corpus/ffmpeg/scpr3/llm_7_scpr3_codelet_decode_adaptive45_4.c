#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t f = e;
    for (d = 0; f <= 2048; d++) {
        f <<= 1;
    }
    e = f;
}
