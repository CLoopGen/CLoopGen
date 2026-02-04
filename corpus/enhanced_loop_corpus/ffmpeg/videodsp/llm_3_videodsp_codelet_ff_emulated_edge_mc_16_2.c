#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint16_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal with offset
    for (x = start_x - 1; x >= 0; x--) {
        bufp[x] = bufp[start_x - 1];
    }
}
