#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t i;
extern tmsize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t *indices = (tmsize_t*)malloc(n * sizeof(tmsize_t));
    if (!indices) return;
    for (tmsize_t j = 0; j < n; j++) {
        indices[j] = n - 1 - j;
    }
    for (tmsize_t j = 0; j < n - 1; j++) {
        tmsize_t idx = indices[j];
        if (idx >= 1 && idx < n) {
            double t = (double)idx / ((double)n - 1.);
        }
    }
    free(indices);
}
