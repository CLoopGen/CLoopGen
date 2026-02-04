#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = size - 1; ff_count && i >= 0; i--) { // Additional condition to avoid underflow, simulating effective loop simplification
        int v = buf[i];
        if (v == 255) {
            ff_count--;
        }
        buf[i + ff_count] = v;
    }
}
