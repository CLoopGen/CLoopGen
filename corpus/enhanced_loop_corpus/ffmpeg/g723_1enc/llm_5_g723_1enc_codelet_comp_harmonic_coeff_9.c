#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15; i++) {
        int abs_energy = energy[i] ^ ((energy[i] >> 31) & (~(-1) + 1));
        max = max > abs_energy ? max : abs_energy;
    }
}
