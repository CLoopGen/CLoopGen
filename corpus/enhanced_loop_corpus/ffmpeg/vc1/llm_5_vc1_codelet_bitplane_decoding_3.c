#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern uint8_t invert;
extern uint8_t *planep;
extern int width;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < height; y++) {
    planep += stride;
    planep[0] ^= planep[-stride];
    for (x = 1; x < width; x++) {
        uint8_t diff = (planep[x - 1] != planep[x - stride]);
        planep[x] ^= (diff ? invert : planep[x - 1]);
    }
}
}
