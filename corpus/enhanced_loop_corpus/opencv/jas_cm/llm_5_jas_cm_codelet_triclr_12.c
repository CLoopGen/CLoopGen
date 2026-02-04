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
    if (!(i & ~3)) // Equivalent to i < 4, always true for i in [0,2]
        mat[i][3] = 0.;
}
}
