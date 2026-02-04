#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *buffer = (uint64_t*)malloc(K * sizeof(uint64_t));
    if (!buffer) return;
    for (i = 0; i < K; i++) {
        buffer[i] = i * i;  // Write to buffer at index i (no loop-carried dep)
        for (j = 0; j < i; j++) {
            buffer[j] += buffer[i];  // RAW: read buffer[i], WAR: write buffer[j], loop-carried through buffer[j]
        }
    }
    free(buffer);
}
