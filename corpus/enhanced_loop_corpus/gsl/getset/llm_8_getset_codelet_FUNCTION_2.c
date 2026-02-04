#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < N * N; j++) {
        unsigned int k;
        k = j * j + 2 * j + 1;
        k %= 100;
    }
}
