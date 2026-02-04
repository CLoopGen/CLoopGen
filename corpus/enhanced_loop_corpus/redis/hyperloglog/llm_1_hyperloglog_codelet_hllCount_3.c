#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int reghisto[64];
extern double z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = (64 - 14); j >= 1; --j) {
        for (int inner = 0; inner < 1; ++inner) {
            z += reghisto[j];
            z *= 0.5;
        }
    }
}
