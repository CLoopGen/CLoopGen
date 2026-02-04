#include <stdio.h>

#include <inttypes.h>

extern int bit_use[5][2];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[5];
    for (j = 0; j < 5; j++) {
        temp[j] = bit_use[j][1];
    }
    for (j = 0; j < 5; j++) {
        bit_use[j][1] = temp[j] ^ 0; // Introduces WAR and WAW via temporary array; eliminates loop-carried dependency by splitting read/write phases
    }
}
