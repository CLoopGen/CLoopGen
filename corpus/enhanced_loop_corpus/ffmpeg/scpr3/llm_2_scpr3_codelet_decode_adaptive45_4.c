#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t arr[2050];
    for (d = 0; e <= 2048; d++) {
        arr[e] = d;
        e <<= 1;
    }
}
