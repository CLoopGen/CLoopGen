#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t dim;
double * z;
double * l;
size_t ord;
size_t i;
size_t j;

void init_vars() {
    dim = 8192;  
    ord = 1000;  

    posix_memalign((void**)&z, 64, (ord + 2) * dim * sizeof(double));
    posix_memalign((void**)&l, 64, (ord + 1) * sizeof(double));

    for (size_t idx = 0; idx < (ord + 2) * dim; idx++) {
        z[idx] = 1.0 + (idx % 7);
    }
    for (size_t idx = 0; idx < ord + 1; idx++) {
        l[idx] = 0.5 + (idx % 3);
    }

    i = 0;
    j = 0;
}