#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int c;
extern int bits;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (c = 0; c < 4; c++) {
        if (c % 2 == 0) {
            bits += steps[c];
        } else {
            continue;
        }
    }
}
