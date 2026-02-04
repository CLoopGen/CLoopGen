#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp[15];
    for (len = 1; len < 15; len++) {
        temp[len] = count[len];
    }
    for (len = 1; len < 15; len++) {
        offs[len + 1] = offs[len] + temp[len];
    }
}
