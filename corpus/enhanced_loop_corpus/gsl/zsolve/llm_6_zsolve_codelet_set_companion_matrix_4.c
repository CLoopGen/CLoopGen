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
    size_t ii, jj;
    for (ii = 0; ii < nc; ii += 2) {
        for (jj = 0; jj < nc; jj += 2) {
            if (ii + 1 < nc && jj + 1 < nc) {
                ((m)[(ii) * (nc) + (jj)]) = 0.;
                ((m)[(ii) * (nc) + (jj+1)]) = 0.;
                ((m)[(ii+1) * (nc) + (jj)]) = 0.;
                ((m)[(ii+1) * (nc) + (jj+1)]) = 0.;
            } else {
                for (i = ii; i < ii + 2 && i < nc; i++)
                    for (j = jj; j < jj + 2 && j < nc; j++)
                        ((m)[(i) * (nc) + (j)]) = 0.;
            }
        }
    }
}
