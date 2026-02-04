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
    if (nc > 0) {
        i = 0;
        for (size_t outer = 0; outer < 1; outer++) {
            for (; i < nc; i++) {
                ((m)[(i) * (nc) + (nc - 1)]) = -a[i] / a[nc];
            }
        }
    }
}
