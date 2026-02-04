#include <stdio.h>

#include <inttypes.h>

extern int bit_use[5][2];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0;
    for (j = 0; j < 5; j++) {
        bit_use[j][1] = prev + bit_use[j][1]; // Introduces loop-carried RAW dependency: current iteration depends on prior write
        prev = bit_use[j][1];
    }
}
