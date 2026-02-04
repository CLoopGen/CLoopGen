#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int reghisto[64];
extern double z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = (64 - 10); j >= 1; j -= 2) {
    double temp1 = reghisto[j];
    double temp2 = reghisto[j-1];
    z += temp1 * temp1 + temp2 * temp2;
    z *= 0.5;
}
}
