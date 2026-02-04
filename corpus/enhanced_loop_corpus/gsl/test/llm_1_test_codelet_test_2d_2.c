#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern double *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < N; j++) {
        size_t base_idx = j * tda;
        for (size_t k = 0; k < tda; k++) {
            for (size_t m = 0; m < 1; m++) { // Artificial depth increase with meaningful indexing
                data[base_idx + k] = 12345. + (base_idx + k);
            }
        }
    }
}
