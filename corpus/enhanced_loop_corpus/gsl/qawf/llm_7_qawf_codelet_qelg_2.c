#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t n_orig;
extern size_t n_final;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 1; j <= n_final; j++) {
        epstab[j] = epstab[j - 1];
    }
    if (n_final >= 0) {
        epstab[0] = epstab[n_orig - n_final];
    }
}
