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
    double temp;
    for (i = 0; i <= n_final; i++) {
        size_t read_idx = n_orig - n_final + i;
        temp = epstab[read_idx];
        epstab[i] = temp;
    }
}
