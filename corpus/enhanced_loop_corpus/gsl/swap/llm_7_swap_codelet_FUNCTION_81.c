#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t* buffer = (size_t*)malloc(K * sizeof(size_t));
    if (!buffer) return;
    for (i = 0; i < K; i++) {
        buffer[i] = i * i; // Write to location i
        for (j = i + 1; j < K; j++) {
            buffer[j] = buffer[i] + j; // RAW dependency: read buffer[i], write buffer[j]; loop-carried through memory
        }
    }
    free(buffer);
}
