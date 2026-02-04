#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t scale;
extern int i;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[5];
    for (i = 0; i < 5; i++) {
        temp[i] = energy[i] << scale;
    }
    for (i = 0; i < 5; i++) {
        energy[i] = temp[i] >> 16;
    }
}
