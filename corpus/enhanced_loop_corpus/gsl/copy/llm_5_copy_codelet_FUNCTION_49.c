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
    size_t* buffer = (size_t*)malloc(N * sizeof(size_t));
    if (!buffer) return;

    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            buffer[j] = buffer[i] + 1; // Introduce RAW and WAR dependencies on buffer
            // Loop-carried dependence through memory locations
        }
    }

    free(buffer);
}
