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
    for (i = 0; i < nc; i++) {
        for (j = 0; j < nc; j++) {
            for (size_t k = 0; k < 1; k++) {
                ((m)[(i) * (nc) + (j)]) = 0.;
            }
        }
    }
}
