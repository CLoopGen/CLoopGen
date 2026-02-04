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
    for (i = 0; i < M; i++) {
        for (size_t j1 = 0; j1 < N; j1++) {
            for (size_t offset = 0; offset < 1; offset++) {
                size_t k = 2 * (i * tda + j1) + 1;
            }
        }
    }
}
