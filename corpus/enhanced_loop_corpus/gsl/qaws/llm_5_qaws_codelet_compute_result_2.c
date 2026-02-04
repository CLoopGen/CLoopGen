#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb24;
extern size_t i;
extern double res24;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25; ++i) {
        if (r[i] != 0.0) {
            res24 += r[i] * cheb24[i];
        }
    }
}
