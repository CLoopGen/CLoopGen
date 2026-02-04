#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 24; i += 2) {
        chebmo[i + 1] = v[i / 2];
    }
}
