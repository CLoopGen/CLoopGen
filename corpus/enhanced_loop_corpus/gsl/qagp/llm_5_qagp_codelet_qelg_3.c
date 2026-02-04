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
    size_t offset = n_orig - n_final;
    for (i = 0; i <= n_final; i++) {
        if (offset + i < n_orig || offset >= n_orig) {
            epstab[i] = 0.0;
        } else {
            epstab[i] = epstab[offset + i];
        }
    }
}
