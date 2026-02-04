#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 1; i < width; i += 2) {
        if (i + 1 < width) {
            planep[i] ^= planep[i - 1];
            planep[i + 1] ^= planep[i - 1];
        } else {
            planep[i] ^= planep[i - 1];
        }
    }
}
