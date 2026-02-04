#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width > 1) {
        for (int outer = 1; outer < width; outer++) {
            planep[outer] ^= planep[outer - 1];
        }
    }
}
