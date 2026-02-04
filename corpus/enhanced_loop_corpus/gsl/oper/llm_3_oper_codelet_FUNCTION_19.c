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
for (i = 0; i < M * tda; i += 2) {
    for (j = 0; j < N; j++) {
        size_t idx = i + j;
        if (idx < M * tda) {
            size_t k = 2 * idx + 1;
        }
    }
}
}
