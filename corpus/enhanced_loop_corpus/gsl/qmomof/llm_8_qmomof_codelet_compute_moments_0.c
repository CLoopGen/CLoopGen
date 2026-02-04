#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 13; i += 2) {
        chebmo[2 * i] = v[i];
        if (i + 1 < 13) {
            chebmo[2 * (i + 1)] = v[i + 1];
        }
    }
}
