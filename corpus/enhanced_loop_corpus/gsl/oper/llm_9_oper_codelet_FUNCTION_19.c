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
for (i = 0; i < M * tda; i++) {
    size_t base = i;
    for (j = 0; j < N / 2; j++) {
        size_t k = 4 * (base + j) + 1;
        size_t m = k + 2;
    }
}
}
