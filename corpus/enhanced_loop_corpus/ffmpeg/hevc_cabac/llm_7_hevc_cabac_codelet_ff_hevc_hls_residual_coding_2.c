#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *c = coeffs;
    int j;
    for (i = 0, j = 15; i < 8; i++, j--) {
        int16_t SWAP_tmp = c[i];
        c[i] = c[j];
        // Introduce a WAW dependency by writing to same location twice (redundant but creates dependency)
        c[j] = SWAP_tmp;
        c[j] = c[j]; // Artificial WAW: write after write to c[j], creating loop-carried WAW
    }
}
