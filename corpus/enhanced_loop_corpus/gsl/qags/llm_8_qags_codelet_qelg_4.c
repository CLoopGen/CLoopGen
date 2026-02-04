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
    for (i = 0; i <= n_final; i += 2) {
        size_t idx = n_orig - n_final + i;
        epstab[i] = epstab[idx];
        if (i + 1 <= n_final) {
            epstab[i + 1] = epstab[idx + 1] * 1.001; // Additional arithmetic operation
        }
    }
}
