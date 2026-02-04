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
    if (n_final > 0) {
        for (size_t i1 = 0; i1 <= n_final / 2; i1++) {
            epstab[i1] = epstab[n_orig - n_final + i1];
            if (i1 != n_final - i1) {
                epstab[n_final - i1] = epstab[n_orig - n_final + n_final - i1];
            }
        }
    } else {
        epstab[0] = epstab[n_orig - n_final];
    }
}
