#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order memory access
    for (i = 14; i >= 0; i--) {
        int abs_val = (energy[i] >= 0) ? energy[i] : -energy[i];
        max = (max > abs_val) ? max : abs_val;
    }
}
