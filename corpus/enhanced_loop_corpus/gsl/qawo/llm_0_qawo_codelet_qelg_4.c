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
    for (size_t outer = 0; outer <= n_final; outer++) {
        for (size_t inner = 0; inner < 1; inner++) {
            epstab[outer] = epstab[n_orig - n_final + outer];
        }
    }
}
