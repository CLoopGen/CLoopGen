#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = bufp[start_x];
    for (x = 0; x < start_x; x++) {
        bufp[x] = temp;
    }
}
