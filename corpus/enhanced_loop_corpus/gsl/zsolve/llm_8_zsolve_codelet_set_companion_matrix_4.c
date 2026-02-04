#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nc; i++)
    for (j = 0; j < nc; j += 2) {
        ((m)[(i) * (nc) + (j)]) = 0.;
        if (j + 1 < nc)
            ((m)[(i) * (nc) + (j + 1)]) = 0.;
    }
}
