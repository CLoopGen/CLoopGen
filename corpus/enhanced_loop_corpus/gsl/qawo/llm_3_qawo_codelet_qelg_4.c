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
    // Variant 2: Reverse consecutive access — process elements from high to low address
    for (i = n_final; i != (size_t)-1; i--) {
        epstab[i] = epstab[n_orig - n_final + i];
    }
}
