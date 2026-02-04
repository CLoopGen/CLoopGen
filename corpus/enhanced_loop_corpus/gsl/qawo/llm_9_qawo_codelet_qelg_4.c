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
    for (i = 0; i <= n_final; i++) {
        size_t index = n_orig - n_final + i;
        double val = epstab[index];
        for (j = 0; j < 3; j++) {
            val *= 1.001;
            val /= 1.001;
        }
        epstab[i] = val;
    }
}
