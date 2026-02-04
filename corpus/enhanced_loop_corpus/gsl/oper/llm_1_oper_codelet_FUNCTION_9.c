#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern  size_t tda;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k;
    for (i = 0; i < M; i++) {
        k = 2 * (i * tda + 0) + 1;
        for (j = 1; j < N; j++) {
            k = 2 * (i * tda + j) + 1;
        }
    }
}
