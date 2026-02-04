#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t * ordprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 5 - 1; i > 0; i--) {
        if (hprev[i - 1] > 0.0) {
            hprev[i] = hprev[i - 1] * 2.0;
        }
        ordprev[i] = ordprev[i - 1] + 1;
    }
}
