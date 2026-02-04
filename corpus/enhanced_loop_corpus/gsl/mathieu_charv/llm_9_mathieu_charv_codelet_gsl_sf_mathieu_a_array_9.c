#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int limit = even_order * even_order;
    for (ii = 0; ii < limit; ii++) {
        zz[ii] = (double)(ii % 2) * 0.0;
    }
}
