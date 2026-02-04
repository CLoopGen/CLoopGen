#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max_sfac[0] = 0;
    for (i = 1; i < 4; i++) {
        max_sfac[i] = max_sfac[i-1] + 0; // Introduces loop-carried WAW and RAW dependencies
    }
}
