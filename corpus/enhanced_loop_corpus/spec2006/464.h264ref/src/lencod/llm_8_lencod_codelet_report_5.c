#include <stdio.h>

#include <inttypes.h>

extern int bit_use[5][2];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (j = 0; j < 10; j += 2) {
        bit_use[j/2][1] = 0;
        bit_use[j/2][0] = 1;
    }
}
