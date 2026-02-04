#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int reghisto[64];
extern double z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; ++k) {
        for (j = (64 - 14); j >= 1; --j) {
            z += reghisto[j];
            z *= 0.5;
        }
    }
}
