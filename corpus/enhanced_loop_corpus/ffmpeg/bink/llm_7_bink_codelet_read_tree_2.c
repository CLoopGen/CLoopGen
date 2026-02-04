#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev = 0;
    for (i = 0; i < 16; i++) {
        in[i] = prev + i;
        prev = in[i] & 0xF;
    }
}
