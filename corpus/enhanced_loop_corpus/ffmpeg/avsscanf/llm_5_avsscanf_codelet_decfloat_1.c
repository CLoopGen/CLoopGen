#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; z > 0; z--) {
        if (!x[z - 1]) continue;
        else break;
    }
}
