#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int c;
extern int bits;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (c = 3; c >= 0; c--) {
        bits += steps[c] * (steps[c] > 0 ? 1 : -1);
        bits += steps[c] >> 1;
    }
}
