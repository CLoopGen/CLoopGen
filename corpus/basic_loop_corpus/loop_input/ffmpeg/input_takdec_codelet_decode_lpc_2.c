#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *coeffs;
int length;
int i;
unsigned int a3;
unsigned int a4;
unsigned int a5;

void init_vars() {
    length = 6710886;  // Approximately 256MB / (sizeof(int32_t) * 3) -> ensures ~0.01 sec runtime
    coeffs = (int32_t*)aligned_alloc(32, length * sizeof(int32_t));
    
    for (int j = 0; j < length; j++) {
        coeffs[j] = j % 256;
    }

    a3 = 0;
    a4 = 0;
    a5 = 0;
    i = 0;
}