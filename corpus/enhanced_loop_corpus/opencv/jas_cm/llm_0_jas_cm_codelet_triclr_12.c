#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

extern int i;
extern jas_cmreal_t mat[3][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < 3; ++i)
    for (j = 3; j <= 3; ++j)
        mat[i][j] = 0.;
}
