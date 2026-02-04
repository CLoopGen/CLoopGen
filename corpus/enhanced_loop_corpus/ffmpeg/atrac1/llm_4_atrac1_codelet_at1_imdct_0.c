#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *spec;
extern int transf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < transf_size / 2; i++) {
        if (i >= 0 && (transf_size - 1 - i) != i) {
            float SWAP_tmp = spec[transf_size - 1 - i];
            spec[transf_size - 1 - i] = spec[i];
            spec[i] = SWAP_tmp;
        }
    }
}
