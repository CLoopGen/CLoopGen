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
    for (i = 0; i <= n_final; i += 2) {
        if (n_orig - n_final + i < n_orig) {
            epstab[i] = epstab[n_orig - n_final + i];
        }
        if (i + 1 <= n_final && n_orig - n_final + i + 1 < n_orig) {
            epstab[i + 1] = epstab[n_orig - n_final + i + 1];
        }
    }
}
