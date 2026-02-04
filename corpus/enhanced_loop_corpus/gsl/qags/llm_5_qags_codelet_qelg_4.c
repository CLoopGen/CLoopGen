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
    for (i = 0; i <= n_final; i++) {
        if (i % 2 == 0) {
            epstab[i] = epstab[n_orig - n_final + i];
        } else {
            epstab[i] = 0.0;
        }
    }
}
