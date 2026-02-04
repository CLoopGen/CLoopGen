#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 12 - 1; i > 0; i--) {
        if (i % 2 == 0) {
            hprev[i] = hprev[i - 1];
        } else {
            hprev[i] = 0.0;
        }
    }
}
