#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

extern int i;
extern jas_cmreal_t mat[3][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; ++i) {
        mat[i][3] = 0.0;
        mat[i][3] += 1.0;
        mat[i][3] -= 1.0;
    }
}
