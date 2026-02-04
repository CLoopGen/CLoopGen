#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[16];
    for (i = 0; i < 16; i++) {
        temp[i] = i;
    }
    for (i = 0; i < 16; i++) {
        in[i] = temp[i];
    }
}
