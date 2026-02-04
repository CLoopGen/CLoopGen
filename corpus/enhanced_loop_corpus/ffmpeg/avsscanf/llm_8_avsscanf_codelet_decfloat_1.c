#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = z;
    for (; i > 0 && !x[i - 1]; i -= 2) {
        if (i - 2 >= 0 && x[i - 2]) break;
    }
    z = i;
}
