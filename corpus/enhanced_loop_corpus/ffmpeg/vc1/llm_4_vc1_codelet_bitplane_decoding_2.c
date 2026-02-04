#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width <= 1) return;
    for (x = 1; x < width; x++) {
        if (planep[x - 1] != 0) {
            planep[x] ^= planep[x - 1];
        }
    }
}
