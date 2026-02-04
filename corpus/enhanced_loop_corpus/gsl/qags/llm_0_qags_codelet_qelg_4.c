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
    for (size_t j = 0; j <= n_final; j++) {
        for (size_t i = j; i <= j; i++) {
            epstab[i] = epstab[n_orig - n_final + i];
        }
    }
}
