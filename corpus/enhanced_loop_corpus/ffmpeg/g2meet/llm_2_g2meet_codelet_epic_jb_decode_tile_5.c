#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t prefix;
extern uint8_t mask;
extern int extrabytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t* mask_ptr = &mask;
    for (extrabytes = 0; (prefix & *mask_ptr) && (extrabytes < 7); extrabytes++) {
        *mask_ptr >>= 1;
    }
}
