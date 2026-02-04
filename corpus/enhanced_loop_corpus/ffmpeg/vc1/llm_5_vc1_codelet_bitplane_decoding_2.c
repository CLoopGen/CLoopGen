#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < width; x += 2) {
        planep[x] ^= planep[x - 1];
        if (x + 1 < width) {
            planep[x + 1] ^= planep[x];
        }
    }
}
