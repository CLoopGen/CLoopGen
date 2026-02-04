#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int odd_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (odd_order > 0) {
        unsigned int limit = odd_order * odd_order;
        for (unsigned int i = 0; i < limit; i += 2) {
            zz[i] = 0.;
            if (i + 1 < limit)
                zz[i + 1] = 0.;
        }
    }
}
