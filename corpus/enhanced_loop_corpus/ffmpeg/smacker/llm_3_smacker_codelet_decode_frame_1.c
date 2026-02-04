#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating direction (ping-pong pattern)
    int j;
    for (j = 0; j < 4; j++) {
        *((uint32_t *)(out + j * stride * ((j % 2 == 0) ? 1 : -1))) = col;
    }
}
