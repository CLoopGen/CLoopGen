#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2, wrap-around using modulo)
    for (i = 0; i < 15; i++) {
        int idx = (i * 2) % 15; // Strided access with stride 2
        int abs_val = (energy[idx] >= 0) ? energy[idx] : -energy[idx];
        max = (max > abs_val) ? max : abs_val;
    }
}
