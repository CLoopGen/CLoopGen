#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern double *alpha;
extern double *c;
extern double *z;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < N; i++) {
        temp = z[i] / alpha[i];
        c[i] = temp;
    }
}
