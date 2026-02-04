#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t scale;
extern int i;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        if (energy[i] != 0) {
            energy[i] = (energy[i] << scale) >> 16;
        } else {
            energy[i] = 0;
        }
    }
}
