#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t prefix;
extern uint8_t mask;
extern int extrabytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extrabytes = 0; (prefix & mask) && (extrabytes < 7); extrabytes++) {
        if (!mask) break;
        mask >>= 1;
    }
}
