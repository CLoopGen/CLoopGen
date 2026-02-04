#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *spec;
extern int transf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < transf_size / 4; i++) {
        float SWAP_tmp1 = spec[transf_size - 1 - i];
        float SWAP_tmp2 = spec[transf_size - 2 - i];
        spec[transf_size - 1 - i] = spec[i];
        spec[i] = SWAP_tmp1;
        spec[transf_size - 2 - i] = spec[i + 1];
        spec[i + 1] = SWAP_tmp2;
    }
}
