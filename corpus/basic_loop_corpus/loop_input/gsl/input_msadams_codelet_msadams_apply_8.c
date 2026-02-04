#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double * l;
size_t ord;
size_t i;

void init_vars() {
    ord = 10000000; // 10 million elements for ~0.01 sec runtime
    l = (double*)aligned_alloc(32, (ord + 2) * sizeof(double));
    if (!l) {
        exit(1);
    }
    for (size_t idx = 0; idx < ord + 2; idx++) {
        l[idx] = 1.0;
    }
}