#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        ((data)[2 * (i)]) = 0.;
        if (i < 64) {
            ((data)[2 * (i) + 1]) = 0.;
        }
    }
}
