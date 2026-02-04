#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t n;
size_t i;
size_t k;
size_t s;
size_t t;
size_t * pp;
size_t * qq;

void init_vars() {
    const size_t data_size = (1 << 20); 
    n = data_size;
    t = n; 

    pp = (size_t*)aligned_alloc(64, n * sizeof(size_t));
    qq = (size_t*)aligned_alloc(64, n * sizeof(size_t));

    for (size_t idx = 0; idx < n; idx++) {
        if (idx == 0) {
            pp[idx] = n - 1;
        } else {
            pp[idx] = idx - 1;
        }
    }

    for (size_t idx = 0; idx < n; idx++) {
        qq[idx] = 0;
    }

    i = 0;
    k = 0;
    s = 0;
}