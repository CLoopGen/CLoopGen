#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

extern int i;
extern jas_cmreal_t mat[3][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < 1; ++i)
    for (int k = 0; k < 3; ++k)
        mat[k][3] = 0.;
}
