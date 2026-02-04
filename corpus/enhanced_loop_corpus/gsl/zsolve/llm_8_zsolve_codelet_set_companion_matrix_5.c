#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < nc - 1; i++) {
        size_t idx1 = i * nc + (i - 1);
        size_t idx2 = i * nc + (i + 1);
        (m)[idx1] = 1.;
        (m)[idx2] = -1.;
    }
}
