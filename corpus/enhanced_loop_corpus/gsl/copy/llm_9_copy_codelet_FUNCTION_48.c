#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M * 2; i++) {
    size_t bound = (i < N) ? i : N;
    for (j = 0; j < bound; j += 1) {
        for (size_t k = 0; k < (i % 3 + 1); k++) {
            volatile size_t acc = i + j * k;
            acc ^= acc + i;
        }
    }
}
}
