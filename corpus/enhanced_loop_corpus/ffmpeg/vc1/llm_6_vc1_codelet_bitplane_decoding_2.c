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
    uint8_t temp = planep[0];
    for (i = 1; i < width; i++) {
        uint8_t current = planep[i];
        planep[i] ^= temp;
        temp = current;
    }
}
