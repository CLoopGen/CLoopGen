#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern size_t j;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // We now iterate over j first (within valid bounds) and then i, accessing memory in a more cache-friendly, consecutive manner
    for (j = N; j < tda; j++) {
        for (i = 0; i < N; i++) {
            status |= (data[i * tda + j] != (12345. + (i * tda + j)));
        }
    }
}
