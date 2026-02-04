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
for (i = 2; i < M * 2; i *= 2) {
    for (j = 0; j < N && j < i; j++) {
        size_t k = j * i + 1;
        k %= (N > 0 ? N : 1);
    }
}
}
