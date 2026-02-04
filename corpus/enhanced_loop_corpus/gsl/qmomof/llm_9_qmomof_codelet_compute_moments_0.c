#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 26; i++) {
        size_t idx = i / 2;
        chebmo[i] = (i % 2 == 0) ? v[idx] : (v[idx] + v[idx] * 0.5);
    }
}
