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
    for (x = 1; x < width; x++) {
        uint8_t temp = planep[x - stride] ^ invert;
        if (planep[x - 1] != planep[x - stride]) {
            planep[x] ^= temp;
        } else {
            planep[x] ^= planep[x - 1];
        }
    }
    planep[0] ^= planep[-stride]; // Move independent operation to end to break WAW on planep[0]
}
}
