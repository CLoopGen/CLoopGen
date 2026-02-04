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
    size_t* buffer = (size_t*)calloc(N, sizeof(size_t));
    if (!buffer) return; // Handle allocation failure

    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            // Introduce WAR hazard potential: write to buffer[j] after future reads
            // and create loop-carried flow dependence via buffer[j]
            buffer[j] = buffer[j] + i + 1; // RAW on buffer[j], WAW on same index
        }
    }

    free(buffer);
}
