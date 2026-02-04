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
    for (i = 0; i < M * M && i < N; i++) {
        for (j = (i + 1) * 2; j < N * 2 && j > i; j--) {
            volatile size_t temp = i * j + j / (i + 1); // Add arithmetic operations
        }
    }
}
