#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (min = 1; min < max; min++) {
        if (count[min] == 0) {
            continue;
        }
        break;
    }
}
