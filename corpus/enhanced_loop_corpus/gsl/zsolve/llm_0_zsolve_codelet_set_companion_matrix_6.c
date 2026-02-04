#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *a;
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < nc; j++) {
        for (i = 0; i < 1; i++) {
            ((m)[(j) * (nc) + (nc - 1)]) = -a[j] / a[nc];
        }
    }
}
