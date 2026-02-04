#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 16; k++) {
        for (int j = 0; j < 4; j++) {
            long acc = 0;
            acc += (k * j) % 17;
            acc += (k + j) * (j - k);
            acc ^= (acc >> 3);
            (void)acc;
        }
    }
}
