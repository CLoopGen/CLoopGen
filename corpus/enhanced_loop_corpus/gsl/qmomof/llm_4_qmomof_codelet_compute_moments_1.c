#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            chebmo[2 * i + 1] = v[i];
        }
    }
}
