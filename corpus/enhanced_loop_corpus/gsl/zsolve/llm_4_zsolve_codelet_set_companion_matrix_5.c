#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < nc; i++) {
        if (i % 2 == 0)
            ((m)[(i) * (nc) + (i - 1)]) = 1.;
    }
}
