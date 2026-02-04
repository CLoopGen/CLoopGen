#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp[12];
    for (i = 1; i < 12; i++) {
        temp[i] = hprev[i - 1];
    }
    for (i = 1; i < 12; i++) {
        hprev[i] = temp[i];
    }
}
