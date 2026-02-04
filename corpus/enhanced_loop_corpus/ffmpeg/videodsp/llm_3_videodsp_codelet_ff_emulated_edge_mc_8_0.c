#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – traverse from end to beginning
    for (int i = start_x - 1; i >= 0; i--) {
        bufp[i] = bufp[start_x];
    }
}
