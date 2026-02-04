#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int reghisto[64];
extern double z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = z;
    for (j = (64 - 14); j >= 1; --j) {
        temp += reghisto[j];
        temp *= 0.5;
    }
    z = temp;
}
