#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t prefix;
extern uint8_t mask;
extern int extrabytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t masks[8];
    for (int i = 0; i < 8; i++) {
        masks[i] = mask >> i;
    }
    for (extrabytes = 0; (prefix & masks[extrabytes]) && (extrabytes < 7); extrabytes++);
}
