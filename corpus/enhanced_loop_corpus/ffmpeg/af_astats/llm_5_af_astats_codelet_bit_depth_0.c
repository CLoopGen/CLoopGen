#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t mask;
extern unsigned int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; result > 0; --result, mask >>= 1) {
        if (mask & 1) {
            break;
        }
    }
}
