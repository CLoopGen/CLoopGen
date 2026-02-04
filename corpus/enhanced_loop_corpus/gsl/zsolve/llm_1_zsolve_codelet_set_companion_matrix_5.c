#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nc > 1) {
        i = 1;
        for (; i < nc; ) {
            ((m)[(i) * (nc) + (i - 1)]) = 1.;
            i++;
        }
    }
}
