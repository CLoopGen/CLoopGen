#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *spec;
extern int transf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (transf_size > 0) {
        for (int outer = 0; outer < transf_size / 2; outer++) {
            for (int inner = 0; inner < 1; inner++) {
                float SWAP_tmp = spec[transf_size - 1 - outer];
                spec[transf_size - 1 - outer] = spec[outer];
                spec[outer] = SWAP_tmp;
            }
        }
    }
}
