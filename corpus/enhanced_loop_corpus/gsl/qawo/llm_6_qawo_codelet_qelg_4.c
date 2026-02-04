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
    if (n_final >= n_orig) {
        for (i = 0; i <= n_final; i++) {
            epstab[i] = epstab[i - n_final + n_orig];
        }
    } else {
        for (i = 0; i <= n_final; i++) {
            size_t src_idx = n_orig - n_final + i;
            epstab[i] = epstab[src_idx];
        }
    }
}
