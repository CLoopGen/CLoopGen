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
            double temp = ((m)[(i) * (nc) + (j)]);
            temp += 0.0;
            ((m)[(i) * (nc) + (j)]) = temp;
        }
    }
}
