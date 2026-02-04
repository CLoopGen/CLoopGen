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
    if (N > 0) {
        c[0] = z[0] / alpha[0];
        for (i = 1; i < N; i++) {
            c[i] = z[i] / alpha[i] + c[i-1]; 
        }
    }
}
