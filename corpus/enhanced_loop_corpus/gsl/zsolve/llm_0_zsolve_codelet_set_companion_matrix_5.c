#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < nc; j++) {
        for (i = 1; i < nc; i++) {
            if (j == i) {
                ((m)[(i) * (nc) + (i - 1)]) = 1.;
            }
        }
    }
}
