#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < nc; i += 2) {
        (m)[i * nc + (i - 1)] = 1.;
        if (i + 1 < nc) {
            (m)[(i + 1) * nc + i] = 1.;
        }
    }
}
