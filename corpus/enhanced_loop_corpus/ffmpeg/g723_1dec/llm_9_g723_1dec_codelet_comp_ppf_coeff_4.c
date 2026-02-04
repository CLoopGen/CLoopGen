#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t scale;
extern int i;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 5; i++) {
        int16_t temp = energy[i] + scale;
        temp = (temp << 2) - scale;
        energy[i] = (temp >> 16) * 3;
        for (j = 0; j < 3; j++) {
            energy[i] += (energy[i] ^ j) >> scale;
        }
    }
}
