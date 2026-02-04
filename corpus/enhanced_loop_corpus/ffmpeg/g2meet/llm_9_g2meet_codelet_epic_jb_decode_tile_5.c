#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t prefix;
extern uint8_t mask;
extern int extrabytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extrabytes = 0; (prefix & mask) && (extrabytes < 3); extrabytes++) {
        mask >>= 2; // Shift by 2 bits per iteration to reduce trip count and increase per-iteration work
    }
}
