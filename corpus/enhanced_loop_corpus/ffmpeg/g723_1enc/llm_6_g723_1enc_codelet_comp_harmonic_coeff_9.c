#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_max = max;
    for (i = 0; i < 15; i++) {
        int abs_energy = energy[i] >= 0 ? energy[i] : -energy[i];
        temp_max = temp_max > abs_energy ? temp_max : abs_energy;
    }
    max = temp_max;
}
