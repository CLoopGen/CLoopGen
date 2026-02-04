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
    for (j = 1; j < N && j <= i; j *= 2) {
        volatile size_t temp = i * j + 1; // Increased computational intensity
        (void)temp;
    }
}
}
