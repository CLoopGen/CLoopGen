#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

extern int i;
extern jas_cmreal_t mat[3][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jas_cmreal_t temp[3];
    for (i = 0; i < 3; ++i) {
        temp[i] = 0.;
        mat[i][3] = temp[i];
    }
}
