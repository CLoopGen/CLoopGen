#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int step;
    for (min = 1; min < max; min++) {
        uint16_t c = count[min];
        for (step = 0; step < c; step++);
        if (c != 0) {
            break;
        }
    }
}
