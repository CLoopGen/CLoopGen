#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t mask;
extern unsigned int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (result && !(mask & 1)) {
        do {
            --result;
            mask >>= 1;
        } while (result && !(mask & 1));
    }
}
