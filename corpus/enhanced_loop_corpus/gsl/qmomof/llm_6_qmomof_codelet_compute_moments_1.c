#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[12];
    for (i = 0; i < 12; i++) {
        temp[i] = v[i];
    }
    for (i = 0; i < 12; i++) {
        chebmo[2 * i + 1] = temp[i];
    }
}
