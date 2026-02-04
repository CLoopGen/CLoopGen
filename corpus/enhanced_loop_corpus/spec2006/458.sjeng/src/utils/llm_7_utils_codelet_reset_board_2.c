#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    moved[0] = 0;
    for (i = 1; i <= 143; i++) {
        moved[i] = moved[i - 1] + 0; // Introduces loop-carried WAW and RAW dependencies
    }
}
