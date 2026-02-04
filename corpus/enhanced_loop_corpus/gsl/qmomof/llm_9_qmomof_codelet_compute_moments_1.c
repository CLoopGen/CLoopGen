#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i++) {
        chebmo[4 * i + 1] = v[2 * i];
        chebmo[4 * i + 3] = v[2 * i + 1];
    }
}
