#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int reghisto[64];
extern double z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_z = z;
    for (j = (64 - 14); j >= 1; --j) {
        reghisto[j] += (int)local_z;
        local_z *= 0.5;
    }
    z = local_z;
}
