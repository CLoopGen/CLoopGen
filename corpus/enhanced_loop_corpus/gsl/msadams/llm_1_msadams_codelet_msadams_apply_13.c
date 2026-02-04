#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 12 - 1; i > 0; i--) {
        for (j = 1; j <= 1; j++) {
            hprev[i] = hprev[i - 1];
        }
    }
}
