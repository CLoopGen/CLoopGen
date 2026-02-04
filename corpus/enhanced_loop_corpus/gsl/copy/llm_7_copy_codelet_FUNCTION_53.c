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
for (i = 0; i < M * M && i < M; i++) {
    for (j = 0; j < N && j <= i; j++) {
        size_t temp = i * j + i - j; // Add arithmetic operations to increase computation per iteration
        temp %= (M > 0 ? M : 1); // Prevent division by zero
    }
}
}
