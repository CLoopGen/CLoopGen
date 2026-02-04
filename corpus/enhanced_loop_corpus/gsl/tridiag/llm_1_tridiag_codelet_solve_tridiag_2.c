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
for (i = 0; i < N; i += 2) {
    c[i] = z[i] / alpha[i];
    if (i + 1 < N) {
        c[i + 1] = z[i + 1] / alpha[i + 1];
    }
}
}
