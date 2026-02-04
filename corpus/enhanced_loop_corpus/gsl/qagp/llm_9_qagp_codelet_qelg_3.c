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
        size_t index = n_orig - n_final;
        double sum = 0.0;
        for (j = 0; j < 3; j++) {
            sum += epstab[index + i] * (1.0 + (j * 0.1));
        }
        epstab[i] = sum / 3.0;
    }
}
