#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < stride * height; x++) {
        if (planep[x] == 1)
            planep[x] = 0;
        else
            planep[x] = 1;
    }
}
