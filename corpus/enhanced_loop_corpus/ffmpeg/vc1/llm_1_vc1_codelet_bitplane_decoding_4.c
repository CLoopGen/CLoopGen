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
    for (int i = 0; i < stride * height; i += 2) {
        planep[i] = !planep[i];
        if (i + 1 < stride * height)
            planep[i + 1] = !planep[i + 1];
    }
}
