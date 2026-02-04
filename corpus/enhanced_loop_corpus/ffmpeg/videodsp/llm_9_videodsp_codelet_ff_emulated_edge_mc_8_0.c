#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = start_x * 2;
    for (x = 0; x < limit; x++) {
        int index = x % start_x;
        bufp[index] = bufp[start_x];
    }
}
