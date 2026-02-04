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
for (y = 2; y < height - 1; y += 2) {
    planep += stride * 2;
    planep[0] ^= planep[-stride];
    planep[1] ^= planep[-stride + 1];
    for (x = 2; x < width - 1; x += 2) {
        if (planep[x - 1] != planep[x - stride])
            planep[x] ^= invert;
        else
            planep[x] ^= planep[x - 1];
        
        if (planep[x] != planep[x - stride + 1])
            planep[x + 1] ^= invert;
        else
            planep[x + 1] ^= planep[x];
    }
}
}
