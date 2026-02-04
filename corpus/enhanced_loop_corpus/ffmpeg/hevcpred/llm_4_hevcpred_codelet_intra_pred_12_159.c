#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; i++) {
        if (i % 2 == 0) {
            left[i] = ((64 - (i + 1)) * left[-1] + (i + 1) * left[63] + 32) >> 6;
        } else {
            left[i] = ((64 - (i + 1)) * left[-1] + (i + 1) * left[63] + 48) >> 6;
        }
    }
}
